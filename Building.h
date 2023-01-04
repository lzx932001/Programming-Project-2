#pragma once
#include <iostream>
using namespace std;

//Singly Linked-List class
class Building
{
private:
	string buildName; //show the building name
	int buildCost;	//show the building cost
	int buildIncome;	//show the building income
public:
	Building* next;	//the address of the next building
	
	//constructor
	Building()
	{
		buildName = "";
		buildCost = 0;
		buildIncome = 0;
		next = nullptr;
	}
	Building(string bName, int bCost, int bIncome)
	{
		buildName = bName;
		buildCost = bCost;
		buildIncome = bIncome;
		next = nullptr;
	}
	Building(string bName, int bCost, int bIncome, Building* p)
	{
		buildName = bName;
		buildCost = bCost;
		buildIncome = bIncome;
		next = p;
	}
	//Destructor
	~Building() {};

	//Getters and Setters
	string getName()
	{
		return buildName;
	}
	string setName(string bName)
	{
		buildName = bName;
		return buildName;
	}
	int getCost()
	{
		return buildCost;
	}
	int setCost(int bCost)
	{
		buildCost = bCost;
		return buildCost;
	}
	int getIncome()
	{
		return buildIncome;
	}
	int setIncome(int bIncome)
	{
		buildIncome = bIncome;
		return buildIncome;
	}
};