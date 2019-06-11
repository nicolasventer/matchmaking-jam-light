#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string& s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

#define TYPE_COUNT 3
#define MAP_COUNT 3

string typeArray[TYPE_COUNT] = { "T", "H", "D" };
string mapArray[MAP_COUNT] = { "u_castle", "u_city", "u_mill" };

#define NAME_INDEX 0
#define TYPE_INDEX 1
#define MAP_INDEX 2
#define ELO_INDEX 3

#define TEAM_SIZE 5
#define TEAM_COUNT_BY_GAME 2

int typeCountByTeamArray[TYPE_COUNT] = { 1, 1, 3 };

int halfMaxDiffElo = 10;

struct Player
{
public:
	Player() {} // do not use
	explicit Player(const string& playerString)
	{
		vector<string> splitPlayerString = split(playerString, ';');
		name = splitPlayerString[NAME_INDEX];
		indexType = find(typeArray, typeArray + TYPE_COUNT, splitPlayerString[TYPE_INDEX]) - typeArray;
		indexMap = find(mapArray, mapArray + MAP_COUNT, splitPlayerString[MAP_INDEX]) - mapArray;
		elo = stoi(splitPlayerString[ELO_INDEX]);
		if (indexType == TYPE_COUNT)
			throw "type not found";
		if (indexMap == MAP_COUNT)
			throw "map not found";
		isValid = true;
	}
	friend bool operator<(const Player& lhs, const Player& rhs)
	{
		return lhs.indexType == rhs.indexType ?
			lhs.indexMap == rhs.indexMap ?
			lhs.name < rhs.name :
			lhs.indexMap < rhs.indexMap :
			lhs.indexType == rhs.indexType;
	}
	inline friend ostream& operator<<(ostream& os, const Player& player) { return os << player.name; }
	string name;
	int indexType = -1;
	int indexMap = -1;
	int elo = -1;
	bool isValid = false;
};

class Team
{
public:
	Team()
	{
		copy(&typeCountByTeamArray[0], &typeCountByTeamArray[TYPE_COUNT], remainingTypeCountArray);
	}
	inline bool IsPlayerCanBeAdded(Player* player) { return remainingTypeCountArray[player->indexType] >= 1; }
	void AddPlayer(Player* player)
	{
		if(!IsPlayerCanBeAdded(player))
			throw "player can't be added";
		playerArray[size] = player;
		size++;
		remainingTypeCountArray[player->indexType]--;
	}
	void Invalidate()
	{
		for (int i = 0; i < size; i++)
			playerArray[i]->isValid = false;
	}
	void Clean()
	{
		for (int i = 0; i < size; i++)
		{
			if (playerArray[i]->isValid)
				continue;
			remainingTypeCountArray[playerArray[i]->indexType]++;
			size--;
			Player* temp = playerArray[i];
			for (int j = i; j < size; j++)
				playerArray[j] = playerArray[j+1];
			playerArray[size] = temp;
			i--;
		}
	}
	void Delete()
	{
		if(!IsFull())
			throw "team not full";
		for (int i = 0; i < TEAM_SIZE; i++)
			delete playerArray[i];
	}
	friend ostream& operator<<(ostream& os, const Team& team)
	{
		if (team.size == 0)
			return os << ";";
		for (int i = 0; i < team.size-1; i++)
			os << *team.playerArray[i] << ",";
		return os << *team.playerArray[team.size-1] <<";";
	}
	inline bool IsFull() { return size == TEAM_SIZE; }
private:
	Player* playerArray[TEAM_SIZE] = { nullptr };
	int size = 0;
	int remainingTypeCountArray[TYPE_COUNT];
};

class Game
{
public:
	Game() {} // do not use
	Game(int mapToUse, Player* host) : mapToUse(mapToUse), host(host) {}
	void AddPlayerIfPossible(Player* player)
	{
		if (abs(player->elo - host->elo) > halfMaxDiffElo)
			return;
		int indexTeam = 0;
		while (indexTeam < TEAM_COUNT_BY_GAME && !teamArray[indexTeam].IsPlayerCanBeAdded(player))
			indexTeam++;
		if (indexTeam == TEAM_COUNT_BY_GAME)
			return;
		teamArray[indexTeam].AddPlayer(player);
		UpdateIsFull();
	}
	void Invalidate()
	{
		for (int i = 0; i < TEAM_COUNT_BY_GAME; i++)
			teamArray[i].Invalidate();
	}
	void Clean()
	{
		for (int i = 0; i < TEAM_COUNT_BY_GAME; i++)
			teamArray[i].Clean();
		UpdateIsFull();
	}
	void Delete()
	{
		if(!IsFull())
			throw "team not full";
		for (int i = 0; i < TEAM_COUNT_BY_GAME; i++)
			teamArray[i].Delete();
	}
	inline Player* GetHost() { return host; }
	inline bool IsFull() {	return isFull; }
	friend bool operator<(const Game& lhs, const Game& rhs)
	{
		return lhs.host->elo == rhs.host->elo ? lhs.mapToUse < rhs.mapToUse : lhs.host->elo < rhs.host->elo;
	}
	friend ostream& operator<<(ostream& os, const Game& game)
	{
		for (int i = 0; i < TEAM_COUNT_BY_GAME; i++)
			os << game.teamArray[i];
		return os << mapArray[game.mapToUse] << ";" << endl;
	}
private:
	void UpdateIsFull()
	{
		isFull = true;
		for (int i = 0; i < TEAM_COUNT_BY_GAME && isFull; i++)
		{
			if (!teamArray[i].IsFull())
				isFull = false;
		}
	}
private:
	// game param
	int mapToUse = -1;
	Player* host = nullptr;
	// player list
	Team teamArray[TEAM_COUNT_BY_GAME];
	// status
	bool isFull = false;
};

class GameList
{
public:
	GameList() {} // do not use
	explicit GameList(int mapToUse) : mapToUse(mapToUse) {}
	void AddPlayer(Player* player, vector<Game>& availaibleGameList)
	{
		Game gameToAdd = Game(mapToUse, player);
		gameToAdd.AddPlayerIfPossible(player);
		for (auto& game : gameList)
		{
			game.AddPlayerIfPossible(player);
			if (game.IsFull())
				availaibleGameList.push_back(game);
			gameToAdd.AddPlayerIfPossible(game.GetHost());
		}
		gameList.push_back(gameToAdd);
		if (gameToAdd.IsFull())
			availaibleGameList.push_back(gameToAdd);
	}
	void Clean()
	{
		for (int i = 0; i < (int)gameList.size(); i++)
		{
			gameList[i].Clean();
			if (!gameList[i].GetHost()->isValid)
			{
				gameList.erase(gameList.begin()+i);
				i--;
			}
		}
	}
	void UpdatePlayerSet(set<Player*>& playerSet)
	{
		for (auto& game : gameList)
			playerSet.insert(game.GetHost());
	}
	int mapToUse = -1;
private:
	vector<Game> gameList;
};

class Queue
{
public:
	Queue()
	{
		for (int i = 0; i < MAP_COUNT; i++)
			gameListArray[i] = GameList(i);
	}
	~Queue()
	{
		set<Player*> playerSet;
		for (int j = 0; j < MAP_COUNT; j++)
			gameListArray[j].UpdatePlayerSet(playerSet);
		for (Player* player : playerSet)
			delete player;
	}
	void AddPlayer(string playerToAdd)
	{
		Player* player = new Player(playerToAdd);
		vector<Game> availaibleGameList; // = NULL;
		for (int j = 0; j < MAP_COUNT; j++)
		{
			if (j == player->indexMap)
				continue;
			gameListArray[j].AddPlayer(player, availaibleGameList);
		}
		if (availaibleGameList.size() == 0)
			return;
		Game gameToMake = availaibleGameList[0];
		cout << gameToMake;
		gameToMake.Invalidate();
		for (int j = 0; j < MAP_COUNT; j++)
			gameListArray[j].Clean();
		gameToMake.Delete();
	}
	GameList gameListArray[MAP_COUNT];
};

#define IS_READ_FILE false

int main()
{
	Queue queue;
	string player;
	if (IS_READ_FILE)
	{
		ifstream in("input.txt");
		if (!in.is_open())
		{
			cout << "can't open input.txt";
			return 1;
		}
		while (in >> player)
			queue.AddPlayer(player);
		return 0;
	}
	while (cin >> player)
		queue.AddPlayer(player);
	return 0;
}
