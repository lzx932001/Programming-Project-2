#pragma once
#include <iostream>
using namespace std;

//forward declaration
class Visitor;

//Parent class, Player and Worker classes inherit from here
class Human
{
private:
	string fName;	//show the human name

public:
	//Constructor
	Human();
	Human(string lName);
	//Destructor
	~Human();
	
	//Getter and Setter
	string getName();
	string setName(string lName);

	//For polymorphism, child classes can override this function
	virtual void work();

	//Visitor pattern, allow the human object can accept the visitor pointer
	virtual void accept(Visitor& v);

	//Prototype design pattern, allow human object to clone itself
	virtual Human clone();
};