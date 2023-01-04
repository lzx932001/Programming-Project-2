#include "Human.h"
#include "Visitor.h"

//Constructor
Human::Human()
{
	fName = "";
}

Human::Human(string lName)
{
	fName = lName;
}

//Destructor
Human::~Human()
{

}

//Getter and Setter
string Human::getName()
{
	return fName;
}

string Human::setName(string lName)
{
	fName = lName;
	return fName;
}

//do nothing, only for child class to override it
void Human::work()
{

}
//Visitor design pattern
//accept the visitor pointer to visit the action
void Human::accept(Visitor& v)
{
	v.Visit(*this);
}

//Prototype design pattern, allow the object to clone itself
Human Human::clone()
{
	return *this;
}