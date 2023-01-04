#include "Shop.h"
#include <iostream>
using namespace std;

//Constructor
Shop::Shop(int aSize)
{
	if (aSize <= 0)
		throw invalid_argument("Illegal stack size.");
	else
	{
		//create 5 fElements pointer to store the Building pointer
		fElements[0] = new Building();
		fElements[1] = new Building();
		fElements[2] = new Building();
		fElements[3] = new Building();
		fElements[4] = new Building();
		fQueuePointer = 0;
		fQueueSize = aSize;
		fQueuePopValue = 0;
	}
}
//Destructor
Shop::~Shop()
{
	//Delete all the fElements pointer
	delete fElements[0];
	delete fElements[1];
	delete fElements[2];
	delete fElements[3];
	delete fElements[4];
}

//check the size of queue is 0
bool Shop::isEmpty() const
{
	return fQueuePointer == 0;
}
//check the size of queue
int Shop::size() const
{
	return fQueuePointer-fQueuePopValue;
}
//add a Building pointer into queue
void Shop::push(Building* aItem)
{
	if (fQueuePointer < fQueueSize)
		fElements[fQueuePointer++] = aItem;
	else
		throw overflow_error("Queue full.");
}
//remove Building pointer from the Queue
void Shop::pop()
{
	if (!isEmpty())
		fQueuePopValue++;
	else
		throw underflow_error("Queue empty.");
}
//return the front of the building pointer
Building* Shop::front()
{
	if (!isEmpty())
		return fElements[fQueuePopValue];
	else
		throw underflow_error("Queue empty.");
}

//return the back of the building pointer
Building* Shop::back()
{
	if (!isEmpty())
		return fElements[fQueuePointer - 1];
	else
		throw underflow_error("Queue empty.");
}

//display the current building from the shop
void Shop::showShop()
{
	cout << "Shop Name: " << fElements[fQueuePopValue]->getName() << endl;
	cout << "Shop Cost: " << fElements[fQueuePopValue]->getCost() << endl;
	cout << "Shop Income: " << fElements[fQueuePopValue]->getIncome() << endl;
}