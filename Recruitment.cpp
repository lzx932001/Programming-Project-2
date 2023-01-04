#include "Recruitment.h"
#include "Worker.h"

//Constructor
Recruitment::Recruitment(int aSize)
{
	if (aSize <= 0)
		throw invalid_argument("Illegal stack size.");
	else
	{
		//create 5 fElements pointer to store the Worker pointer
		fElements[0] = new Worker();
		fElements[1] = new Worker();
		fElements[2] = new Worker();
		fElements[3] = new Worker();
		fElements[4] = new Worker();
		fStackPointer = 0;
		fStackSize = aSize;
	}
}
//Destructor
Recruitment::~Recruitment()
{
	//Delete all the fElements pointer
	delete fElements[0];
	delete fElements[1];
	delete fElements[2];
	delete fElements[3];
	delete fElements[4];
}
//check the size of stack is 0
bool Recruitment::isEmpty() const
{
	return fStackPointer == 0;
}
//check the size of stack
int Recruitment::size() const
{
	return fStackPointer;
}
//add a Worker pointer into stack
void Recruitment::push(Worker* aItem)
{
	if (fStackPointer < fStackSize)
		fElements[fStackPointer++] = aItem;
	else
		throw overflow_error("Stack full.");
}
//remove Worker pointer from the stack
void Recruitment::pop()
{
	if (!isEmpty())
		fStackPointer--;
	else
		throw underflow_error("Stack empty.");
}
//return the top of the Worker pointer
Worker* Recruitment::top()
{
	if (!isEmpty())
		return fElements[fStackPointer - 1];
	else
		throw underflow_error("Stack empty.");
}

//display the current worker from recruitment
void Recruitment::showRecruitment()
{
	cout << "Worker Name: " << fElements[fStackPointer - 1]->getName() << endl;
	cout << "Worker Cost: " << fElements[fStackPointer - 1]->getCost() << endl;
	cout << "Worker Income: " << fElements[fStackPointer - 1]->getIncome() << endl;
}