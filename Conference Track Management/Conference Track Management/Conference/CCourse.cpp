#include "CCourse.h"

CCourse::CCourse():myName(""), myID(0),myMinute(0), myWeight(0)
{
}
CCourse::CCourse(string name, int id, int minute, int weight)
{
	myName = name;
	myID = id;
	myMinute = minute;
	myWeight = weight;
}
CCourse::~CCourse()
{
}
void CCourse::SetMyName(string name)
{
	myName = name;
}
string CCourse::GetMyName()
{
	return myName;
}
void CCourse::SetMyID(int id)
{
	myID = id;
}
int CCourse::GetMyID()
{
	return myID;
}

void CCourse::SetMyMinute(int minute)
{
	myMinute = minute;
}
int CCourse::GetMyMinute()
{
	return myMinute;
}

void CCourse::SetMyWeight(int weight)
{
	myWeight = weight;
}
int CCourse::GetMyWeight()
{
	return myWeight;
}