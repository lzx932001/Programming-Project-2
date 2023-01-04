#include <iostream>
#include "Player.h"
#include "Building.h"
#include "Shop.h"
#include "Worker.h"
#include "Recruitment.h"
#include "Visitor.h"

using namespace std;

//this function is used for command
char commandList(Player *&player, Shop &shop, Recruitment& r1)
{
	//Represent Array Concept, store all the command into array
	string command[9];
	command[0] = "w: go to work";
	command[1] = "s: go to shop";
	command[2] = "r: go to recruitment";
	command[3] = "b: buy building";
	command[4] = "h: hire worker";
	command[5] = "l: list your buildings";
	command[6] = "d: show worker details";
	command[7] = "n: next day";
	command[8] = "q: quit";
	
	char cInput;	//player input
	bool workaction = false;	//the work state of the player, if player worked today, it then set to true and cannot work again today

	//visitor pointer
	Visitor* V = nullptr;

	do
	{
		cout << "Name: " << player->getName() << endl;
		cout << "Money: " << player->getMoney() << endl;
		//print all the commands
		for (int i = 0; i < 9; i++)
		{
			cout << command[i] << endl;
		}
		cin >> cInput;
		switch (cInput) {
		case 'w':
			//if workaction is false, player then can work
			if (workaction == false)
			{
				V = new VisitorWork(player);
				player->accept(*V);
				delete V;
				V = nullptr;
				//check the player does he own worker
				if (player->isWorker() == true)
				{
					V = new VisitorWork(player);
					player->plyWorker->accept(*V);
					delete V;
					V = nullptr;
				}
				workaction = true;
			}
			else
			{
				cout << "You worked today!" << endl;
			}
			break;
		case 's':
			shop.showShop();
			break;
		case 'b':
			player->buyBuilding(shop);
			break;
		case 'l':
			V = new VisitorShowBuilding();
			player->accept(*V);
			delete V;
			V = nullptr;
			break;
		case 'n':
			cout << "Go to sleep" << endl;
			player->setMoney(player->getMoney() + player->plyLand->totalIncome());
			break;
		case 'q':
			return cInput;
			break;
		case 'r':
			r1.showRecruitment();
			break;
		case 'h':
			player->hireWorker(r1);
			break;
		case 'd':
			V = new VisitorShowWorker();
			player->accept(*V);
			delete V;
			V = nullptr;
			break;
		}
	} while (cInput != 'n');	
}

int main()
{
	cout << "Enter your character name: " << endl;
	string name;
	cin >> name;
	cout << endl;
	Player* p1 = new Player(name);
	Building* b1 = new Building("Grocery Store", 20, 2);
	Building* b2 = new Building("Restaurant", 30, 3, b1);
	Building* b3 = new Building("Hotel", 40, 4, b2);
	Building* b4 = new Building("Bank", 50, 5, b3);
	Building* b5 = new Building("White House", 60, 10, b4);

	//queue object
	Shop shop(5);
	//using FIFO method to store the building
	shop.push(b1);
	shop.push(b2);
	shop.push(b3);
	shop.push(b4);
	shop.push(b5);

	Worker* w1 = new Worker("Spider-Man", 15, 1);
	Worker* w2 = new Worker("Captain America", 20, 2);
	Worker* w3 = new Worker("Thor", 30, 3);
	Worker* w4 = new Worker("Iron Man", 40, 4);
	Worker* w5 = new Worker("Thanos", 50, 5);

	//Prototype design pattern
	Human h1 = w1->clone();
	cout << h1.getName() << endl;

	//Stack object
	Recruitment recruitment(5);
	//using LIFO method to store worker
	recruitment.push(w5);
	recruitment.push(w4);
	recruitment.push(w3);
	recruitment.push(w2);
	recruitment.push(w1);

	int date = 0;
	char result;
	do
	{
		cout << "Day " << date << endl;
		result = commandList(p1, shop, recruitment);
		date++;
	} while (result != 'q'); //if the player input is 'q', end the simulator

	delete p1;
	return 0;
}