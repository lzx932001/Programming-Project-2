#include "Player.h"

//Constructor
Player::Player(string pName) : Human(pName) //pass it back to parent class to initialize
{
	plyMoney = 10;
	plyLand = new Land();
	plyWorker = new Worker();
	workerState = false; //workerState set to false is because player does not own worker at the beginning
}
//destructor
Player::~Player()
{

}
//getters and setters
int Player::getMoney()
{
	return plyMoney;
}

int Player::setMoney(int pMoney)
{
	plyMoney = pMoney;
	return plyMoney;
}
//check the player brought the worker or not
bool Player::isWorker()
{
	return workerState;
}
//allow player go to work and earn money
void Player::work()
{
	setMoney(plyMoney + 2);
}
//buy building from shop
void Player::buyBuilding(Shop& shop)
{
	//check the player money is higher/equal to the building cost
	if (this->getMoney() >= shop.front()->getCost())
	{
		//if true, then add the building into player's land and deduct the player's money
		plyLand->add(shop.front()->getName(), shop.front()->getCost(),shop.front()->getIncome(),this->plyLand->sBuilding, shop.front()->next);
		setMoney(plyMoney - shop.front()->getCost());
		//remove the building from shop
		shop.pop();
	}
}
//display the building that the player brought
void Player::showBuilding()
{
	Building* Index;
	Index = this->plyLand->sBuilding;
	while (Index != nullptr)
	{
		cout << "Building Name: " << Index->getName() << endl;
		cout << "Building Income: " << Index->getIncome() << endl;
		Index = Index->next;
	}
}
//allow player hire worker from recruitment
void Player::hireWorker(Recruitment& r1)
{
	//check the player money is higher/equal to the worker cost
	if (this->getMoney() >= r1.top()->getCost())
	{
		//if true, then add the worker into player's worker pointer and deduct the player's money
		plyWorker = r1.top();
		setMoney(plyMoney - r1.top()->getCost());
		//remove the worker from recruitment
		r1.pop();
		//set the player now own worker
		workerState = true;
	}
	else
	{
		cout << "You do not have enough money to hire a worker! Go to Work!" << endl;
	}
}

//display the worker's details
void Player::showWorker()
{
	if (workerState == true)
	{
		Worker* Index;
		Index = this->plyWorker;
		cout << "Worker Name: " << Index->getName() << endl;
		cout << "Worker Income: " << Index->getIncome() << endl;
	}
	else
	{
		cout << "You do not have worker yet! Go hire one!" << endl;
	}
}

//Visitor deisng pattern, accept the visitor pointer
void Player::accept(Visitor& v)
{
	v.Visit(*this);
}

//Prototype deisng pattern, allow player to clone himself
Human Player::clone()
{
	return Player(*this);
}