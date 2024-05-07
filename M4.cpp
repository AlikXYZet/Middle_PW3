#include <iostream>
#include <cmath>
#include <string>
#include <vector>

class Vector
{
public:
	Vector()
	{
		x = 0;
		y = 0;
		z = 0;
		Info = new std::string("Info");
	}

	Vector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		Info = new std::string("Info");
	}

	Vector(float num)
	{
		x = num;
		y = num;
		z = num;
		Info = new std::string("Info");
	}

	Vector(const Vector& other)
	{
		//std::cout << "\nCopy constructor \n";
		x = other.x;
		y = other.y;
		z = other.z;
		Info = new std::string(*(other.Info));
	}

	Vector& operator=(Vector& other)
	{
		//std::cout << "\noperator = \n";
		x = other.x;
		y = other.y;
		z = other.z;

		if (other.Info)
		{
			if (Info) delete Info;
			Info = new std::string(*(other.Info));
		}

		return (*this);
	}

	~Vector()
	{
		//std::cout << "Destructor calling \n";
		delete Info;
	}

	operator float()
	{
		return sqrt(x * x + y * y + z * z);
	}

	friend Vector operator+(const Vector& a, const Vector& b);

	friend std::ostream& operator<<(std::ostream& out, const Vector& v);

	friend bool operator>(const Vector& a, const Vector& b);

	float operator[](int index)
	{
		switch (index)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		default:
			std::cout << "ibdex error: ";
			return 0;
			break;
		}
	}

private:
	float x;
	float y;
	float z;

	std::string* Info;
};

Vector operator+(const Vector& a, const Vector& b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << v.x << ' ' << v.y << ' ' << v.z;
	return out;
}

bool operator>(const Vector& a, const Vector& b)
{
	return false;
}

class Item
{
private:
	std::string ItemName;

public:
	Item()
	{
		ItemName = "none";
	}

	Item(std::string inItemName)
	{
		ItemName = inItemName;
	}

	void ShowItemName()
	{
		std::cout << ItemName << '\n';
	}
};

class Guild;

class Player
{
private:
	Vector Location;
	Item* MainItem;
	std::string PlayerName;
	std::vector<Guild*> Guilds;

public:
	Player()
	{
		PlayerName = "None";
	}

	Player(std::string inPlayerName, Vector InitialLocation)
	{
		PlayerName = inPlayerName;
		Location = InitialLocation;
	}

	void ShowPlayerInfo()
	{
		std::cout << PlayerName << " is at " << Location << '\n';
		std::cout << PlayerName << " have ";
		if (MainItem)
		{
			MainItem->ShowItemName();
		}
		else
		{
			std::cout << "none\n";
		}
	}

	void SetNewItem(Item* newItem)
	{
		MainItem = newItem;
	}

	void JoinGuild(Guild* guildToJoin)
	{
		Guilds.push_back(guildToJoin);
	}

	friend class Guild;
};

class PlayersParty
{
private:
	Player** players;
	int CurrentPlayersNum;

public:
	PlayersParty()
	{
		CurrentPlayersNum = 0;
		players = new Player * [4];
	}

	void AddPlayerToParty(Player* newPlayer)
	{
		players[CurrentPlayersNum] = newPlayer;
		CurrentPlayersNum++;
	}

	void ShowAllPlayersInfo()
	{
		for (int i = 0; i < CurrentPlayersNum; i++)
		{
			players[i]->ShowPlayerInfo();
		}
	}
};

class Guild
{
private:
	std::vector<Player*> Players;

public:
	void AddNewPlayer(Player* newPlayer)
	{
		newPlayer->JoinGuild(this);
		Players.push_back(newPlayer);
	}

	void RemovePlayer(Player* playerToRemove)
	{
		Players.push_back(playerToRemove);
	}
};

int main()
{
	Item* Sword = new Item("Sword");
	Player* PlayerA = new Player("Somebody", Vector(1, 2, 3));
	PlayerA->SetNewItem(Sword);
	Player* PlayerB = new Player("Second", Vector(1, 5, 8));
	PlayersParty PlayersAB;
	PlayersAB.AddPlayerToParty(PlayerA);
	PlayersAB.AddPlayerToParty(PlayerB);
	PlayersAB.ShowAllPlayersInfo();
}