#include <conio.h>
#include <iostream>
#include <string>
using std::string;

class human
{
protected:
	int health = 100, damage = 0, kills = 0;
	string name = "human1", ability = "none";

public:

	human(int h, int d, int k, string n, string ab) //CONSTRUCTOR OF THE CLASS
	{
		health = h; damage = d; kills = k;
		name = n; ability = n;
	}

	void set_health(int x) { health = x; }

	void set_damage(int x) { damage = x; }

	void set_kills(int x) { kills = x; }

	void set_name(string n) { name = n; }

	void set_ability_type(string n) { ability = n; }

	int get_health() { return health; }

	int get_damage() { return damage; }

	int get_kills() { return kills; }

	string get_name() { return name; }

	string get_ability() { return ability; }

	void deal_damage(int x)
	{
		if (damage >= 0)
		{
			if ((health - x) > 0)
			{
				health -= x;
				damage += x; //track how much damage has been taken: max 100
			}
		}
	}

	void add_health(int x)
	{
		if ((x + health) <= 100)
		{
			health += x; //ONLY INCREASE HEALTH, DAMAGE TAKEN STAYS THE SAME.
			//damage -= x;
		}
	}

};

class enemy : public human
{
	//CLASS ENEMY IS A CHILD OF CLASS HUMAN
public:
	enemy():human(150, 0, 0, "enemy", "steal")
	{
		name = "enemy1"; ability = "steal";
		damage = 0; health = 150; //ALL ENEMIES HAVE MORE HEALTH THAN THE PLAYER
	}
	
	void steal()
	{
		std::cout << name << " is stealing!\n";
	}
};

class player : public human
{

public:

	player() :human(100, 0, 0, "player", "none")
	{
		name = "player1"; ability = "none";
		damage = 0; health = 100;
	}

	bool can_do_magic()
	{
		if (health >= 65)
		{
			return true;
		}

		else { return false; }
	}

	void _attack(enemy obj, char attack_type)
		//attack types: 1. melee (M) 2. magic(K)
	{
		switch (attack_type)
		{
		case 'M':
			obj.deal_damage(10);
			std::cout << "Dealt 10 damage to enemy!\n";
			break;

		case 'K':
			if ( can_do_magic() )
			{
				obj.deal_damage(25);
				std::cout << "Dealt 25 damage to enemy!\n";
				break;
			}
			else
			{
				std::cout << "Can't use magic, get more health!\n";
				break;
			}

		default:
			break;
		}
	}

	void _kill()
	{
		if (damage == 100)
		{
			//KILL THE PLAYER
			std::cout << "Player has too much damage!\n";
			exit(0); //TERMINATE THE GAME:

		}
	}
};

void start_game(player);
void start_game(player obj)
{
	//CHANGE THE PLAYER PROPERTIES WHEN STARTING THE GAME
	std::cout << "Welcome to Battle Of Logic!\n" << "You must first create a player: \n";
	_getch();

	string name = "";
	int selection = 0;

	//PLAYER TYPE WILL DETERMINE THE ABILITIES
	std::cout << "Enter Your Username: ";
	std::cin >> name;
	std::cout << "Choose the number of your player type: (1) Math Oz  \t(2)  Science Wizard  \t(3) The Thinker\n";
	std::cin >> selection;

	obj.set_name(name);

	switch (selection)
	{
		case 1:
			obj.set_ability_type("mr_space");
			break;
		case 2:
			obj.set_ability_type("mr_earth");
			break;
		case 3:
			obj.set_ability_type("mr_books");
			break;
		default:
			obj.set_ability_type("none");
			break;
	}

	std::cout << "Great! Click any button to start\n";
	_getch();

	std::cout << "Game Started!\n";

}

int main() //OPERATIONS FOR RUNNING THE GAME
{
	int selection = 0;
	player p1; enemy e1;

	std::cout << "***Battle Of Logic***\n\n" << "Main Menu\n";

	std::cout << "(1) Start Game  (2)  View Details  (3) Quit Game\n";
	std::cin >> selection;

	switch (selection)
	{
		case 1:
			system("cls");
			start_game(p1);
			break;

		case 2:
			std::cout << "Details available soon..\n";
			_getch();
			break;

		case 3:
			exit(0);
			break;

		default:
			break;
	}


	return 0;
}