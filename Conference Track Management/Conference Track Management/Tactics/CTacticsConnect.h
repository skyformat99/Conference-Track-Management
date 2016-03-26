#pragma once
#include <vector>
#include "CTactics.h"
#include "CTimeLimit.h"
#include "..\Conference\CCourse.h"
using namespace std;
class CTacticsConnect
{
public:
	CTacticsConnect();
	~CTacticsConnect();
	bool IsSatisfy(vector<CCourse>* listPool, vector<CCourse>* list, int count);
private:
	CTactics* myTimeLimit;
	
};

