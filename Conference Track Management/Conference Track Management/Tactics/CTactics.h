#pragma once
#include <vector>
#include "..\Conference\CCourse.h"
using namespace std;

class CTactics
{
public:
	CTactics();
	~CTactics();

	virtual bool IsSatisfy(vector<CCourse>* listPool, vector<CCourse>* list, int count);
private:

};

