#pragma once
#include "CTactics.h"

class CTimeLimit : public  CTactics
{
public:
	CTimeLimit();
	~CTimeLimit();

	bool IsSatisfy(vector<CCourse>* listPool, vector<CCourse>* list, int count);

private:
	bool HasCourseWithID(vector<CCourse>* list, int id);

};

