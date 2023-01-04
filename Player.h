#pragma once
#include <iostream>
#include "Land.h"
#include "Shop.h"
#include "Building.h"
#include "Human.h"
#include "Worker.h"
#include "Recruitment.h"
#include "Visitor.h"
using namespace std;

//this is a derived class, it inherits from Human class
class Player : public Human
{
private:
	int plyMoney;	//show the current money player has
	bool workerState;	//show the player currently owning worker or not, it will set to true after player buy a worker from recruitment

public:
	Land* plyLand; //custom ADT, used to store the building
	Worker* plyWorker;	//the worker owned by the player

	//constructor
	Player(string pName);
	//destructor
	~Player();
	//getters and setters
	int getMoney();
	int setMoney(int pMoney);
	//return the player owning worker or not
	bool isWorker();

	//allow player go to work and earn money
	void work();
	//allow player to buy building from shop and generate income
	void buyBuilding(Shop& shop);
	//display the building owned by player
	void showBuilding();
	//hire the worker from recruitment
	void hireWorker(Recruitment& r1);
	//display the worker hired by player
	void showWorker();

	//Visitor design pattern, allow player to accept the visitor pointer 
	void accept(Visitor& v);
	//Prototype design pattern, allow player to clone himself
	Human clone() override;
};