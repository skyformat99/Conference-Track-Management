#include "CTimeLimit.h"

CTimeLimit::CTimeLimit()
{
}

CTimeLimit::~CTimeLimit()
{
}
bool CTimeLimit::IsSatisfy(vector<CCourse>* listPool, vector<CCourse>* list, int count)
{
	if (count <= 180 && HasCourseWithID(list, 19))
		return false;
	if (count < 420 && HasCourseWithID(list, 19))
		return false;
	if (count > 480 && !HasCourseWithID(list, 19))
		return false;
	if (count == 480 && !HasCourseWithID(list, 19))
	{
		vector<CCourse>::iterator it = listPool->begin();
		while (it != listPool->end())
		{
			if (it->GetMyID() == 19)
			{
				it->SetMyWeight(1);
				it->SetMyMinute(30);
				CCourse *temp = new CCourse(*it);
				list->push_back(*temp);
				//count += temp->GetMyMinute();
				listPool->erase(it);
				return true;
			}
			it++;
		}
	}
	/*
	if ((480 - count) < 35 && !HasCoursrWithID(list, 19))
	{
		for (int i = 0; i < listPool->size(); i++)
		{
			if ((*listPool)[i].GetMyID() == 19)
			{
				vector<CCourse>::iterator it = listPool->begin();
				it += (i - 1);
				list->push_back((*listPool)[i]);
				listPool->erase(it);
				return false;
			}
		}
	}
	*/
	return true;
}
bool CTimeLimit::HasCourseWithID(vector<CCourse>* list, int id)
{
	for (int i = 0; i < list->size(); i++)
	{
		if ((*list)[i].GetMyID() == id)
			return true;
	}
	return false;
}