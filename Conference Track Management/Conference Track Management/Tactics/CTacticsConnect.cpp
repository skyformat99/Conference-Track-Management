#include "CTacticsConnect.h"

CTacticsConnect::CTacticsConnect()
{
	myTimeLimit = new CTimeLimit();
}

CTacticsConnect::~CTacticsConnect()
{
	if (myTimeLimit)
		delete myTimeLimit;
}
bool CTacticsConnect::IsSatisfy(vector<CCourse>* listPool, vector<CCourse>* list, int count)
{
	return myTimeLimit->IsSatisfy(listPool, list, count);
}