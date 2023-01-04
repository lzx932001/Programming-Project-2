#pragma once
#include <iostream>
#include "Human.h"
#include "Player.h"

using namespace std;

//forward declaration
class Human;
class Player;
class Worker;
class Shop;
class Recruitment;

//Visitor design pattern
//visitor parent class
class Visitor
{
public:
	virtual void Visit(Human& H);
	virtual void Visit(Player& P);
	virtual void Visit(Worker& W);
};

//inherit from visitor parent class
//allow player and worker access work()
class VisitorWork : public Visitor
{
private:
	Player* fPlayer;
public:
	VisitorWork(Player* player);
	virtual void Visit(Human& H);
	virtual void Visit(Player& P);
	virtual void Visit(Worker& W);
};

//inherit from visitor parent class
//allow player to display all the building details
class VisitorShowBuilding : public Visitor
{
private:
	
public:
	VisitorShowBuilding();
	virtual void Visit(Player& P);
};

//inherit from visitor parent class
//allow player to display all the worker details
class VisitorShowWorker : public Visitor
{
private:

public:
	VisitorShowWorker();
	virtual void Visit(Player& P);
};