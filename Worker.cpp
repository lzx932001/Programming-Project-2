#include "Worker.h"

//Constructor
//Default constructor is for initialize the player at the beginning
Worker::Worker()
{
	workCost = 0;
	workIncome = 0;
}

//Overloaded Constructor
Worker::Worker(string wName, int wCost, int wIncome) : Human(wName)
{
	workCost = wCost;
	workIncome = wIncome;
}

//Destructor
Worker::~Worker() 
{

};

//Getters and Setters
int Worker::getCost()
{
	return workCost;
}

int Worker::setCost(int wCost)
{
	workCost = wCost;
	return workCost;
}

int Worker::getIncome()
{
	return workIncome;
}

int Worker::setIncome(int wIncome)
{
	workIncome = wIncome;
	return workIncome;
}

//allow worker work for player and generate income
void Worker::work(Player*& player)
{
	player->setMoney(player->getMoney() + player->plyWorker->getIncome());
}

//visitor design pattern, allow worker to accept visitor pointer
void Worker::accept(Visitor& v)
{
	v.Visit(*this);
}

//Prototype design pattern, allow worker to clone himself
Human Worker::clone()
{
	return Worker(*this);
}