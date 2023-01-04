#pragma once
#include <iostream>
using namespace std;

//forward declaration
class Worker;

//Represent Stack Concept
class Recruitment
{
private:
	Worker* fElements[5]; //store the pointer array of worker
	int fStackPointer;	//the index of the pointer array
	int fStackSize; //the size of the stack
public:
	//Constructor
	Recruitment(int aSize);
	//Destructor
	~Recruitment();

	//check if the stack is empty
	bool isEmpty() const;
	//return the size of stack
	int size() const;
	//add the pointer to the stack
	void push(Worker* aItem);
	//remove the pointer from the stack
	void pop();
	//show the top pointer of the stack
	Worker* top();

	//display the cuurent worker from recruitment
	void showRecruitment();
};