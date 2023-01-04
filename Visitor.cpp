#include "Visitor.h"

//Visitor design pattern
//visitor parent class
void Visitor::Visit(Human& H)
{}
void Visitor::Visit(Player& P)
{}
void Visitor::Visit(Worker& W)
{}

//VisitorWork Constructor
VisitorWork::VisitorWork(Player* player)
{
	fPlayer = player;
}
//allow human to access work()
void VisitorWork::Visit(Human& H)
{
	H.work();
}
//allow player to access work()
void VisitorWork::Visit(Player& P)
{
	P.work();
}
//allow worker to access work()
void VisitorWork::Visit(Worker& W)
{
	W.work(fPlayer);
}

//VisitorShowBuilding Constructor
VisitorShowBuilding::VisitorShowBuilding()
{
	
}

//allow player to display the building details
void VisitorShowBuilding::Visit(Player& p)
{
	p.showBuilding();
}

//VisitorShowWorker Constructor
VisitorShowWorker::VisitorShowWorker()
{

}

//allow player to display the worker details
void VisitorShowWorker::Visit(Player& p)
{
	p.showWorker();
}