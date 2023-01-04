#pragma once
#include <iostream>
#include "Building.h"
using namespace std;

//Represent Queue Concept
class Shop
{
private:
	Building* fElements[5]; //store the pointer array of Building
	int fQueuePointer;	//the index of the pointer array
	int fQueueSize; //the size of the queue
	int fQueuePopValue; //the first element of the queue
public:
	//Constructor
	Shop(int aSize);
	//Destructor
	~Shop();

	//check if the queue is empty
	bool isEmpty() const;
	//return the size of queue
	int size() const;
	//add the pointer to the queue
	void push(Building* aItem);
	//remove the pointer from the queue
	void pop();
	//show the front pointer of the queue
	Building* front();
	//show the back pointer of the queue
	Building* back();

	//display the current building from the shop
	void showShop();
};