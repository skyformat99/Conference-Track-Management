#include "CTrackManager.h"
#include <iostream>

CTrackManager::CTrackManager():myCounter(0)
{
	myCourse = new vector<CCourse>();
	myConnect = new CTacticsConnect();
	myRandom = new CRandom();
	myTempList = new vector<CCourse>();
	myMorningList = new vector<CCourse>();
	myAfternoonList = new vector<CCourse>();
	myTotalList = new vector<CCourse>();
}

CTrackManager::~CTrackManager()
{
	if (myCourse)
	{
		myCourse->clear();
		delete myCourse;
	}
	if (myConnect)
		delete myConnect;
	if (myRandom)
		delete myRandom;
	if (myTempList)
	{
		myTempList->clear();
		delete myTempList;
	}
	if (myMorningList)
	{
		myMorningList->clear();
		delete myMorningList;
	}
	if (myAfternoonList)
	{
		myAfternoonList->clear();
		delete myAfternoonList;
	}
	if (myTotalList)
	{
		myTotalList->clear();
		delete myTotalList;
	}	
}

void CTrackManager::SetMyCourses(vector<CCourse>* list)
{
	myCourse = list;
}
vector<CCourse>* CTrackManager::BuildTrack()
{
	myTempList = new vector<CCourse>(*myCourse);
	myMorningList->clear();
	myAfternoonList->clear();
	myTotalList->clear();
	//test();

	myCounter = 0;
	GetMorningTrack();

	myCounter = 240;
	//tempList = RemoveMorningList();
	GetAfternoonTrack();
	MergeList();
	return myTotalList;
}
void CTrackManager::GetMorningTrack()
{
	while (1)
	{
		if (myCounter < 180)
		{
			if (myConnect->IsSatisfy(myTempList, myMorningList, myCounter))
			{
				if ((180 - myCounter) < 30)
				{
					vector<CCourse>::iterator it = myTempList->begin();
					while (it != myTempList->end())
					{
						if (it->GetMyMinute() == 0 && it->GetMyID() != 19)
						{
							(*it).SetMyMinute(180 - myCounter);
							it->SetMyWeight(1);
							CCourse *temp = new CCourse(*it);
							myMorningList->push_back(*temp);
							myCounter += temp->GetMyMinute();
							myTempList->erase(it);
							break;
						}
						it++;
					}
					if (180 == myCounter)
						continue;
				}
				CCourse* temp = GetOneCourse(myRandom->GetRandom(1, myTempList->size()));
				if (temp)
				{
					AddCourseToList(myMorningList, temp);
				}
				else
				{
					TempListMakeToZero();
					RemoveCourseToTempList(myMorningList);
				}
			}
			else
			{
				RemoveCourseToTempList(myMorningList);
			}
		}
		else if (myCounter > 180)
		{
			RemoveCourseToTempList(myMorningList);
		}
		else
		{
			if (myConnect->IsSatisfy(myTempList, myMorningList, myCounter))
			{
				break;
			}
			else
			{
				RemoveCourseToTempList(myMorningList);
			}
		}
	}

	/*
	while (1)
	{
		if (counter <180)
		{
			if ((180 - counter) < 30)
			{
				vector<CCourse>::iterator it = tempList->begin();
				while (it != tempList->end())
				{
					if (it->GetMyMinute() == 0 && it->GetMyID() != 19)
					{
						(*it).SetMyMinute(180 - counter);
						it->SetMyWeight(1);
						CCourse *temp = new CCourse(*it);
						myMorningList->push_back(*temp);
						counter += temp->GetMyMinute();
						tempList->erase(it);
						break;
					}
					it++;
				}
				if (180 == counter)
					continue;
				else
					RemoveCourseToTempList(myMorningList);

			}
			CCourse* temp = GetOneCourse(myRandom->GetRandom(1, tempList->size()));
			if (temp)
			{
				//myMorningList->push_back(*temp);
				//counter += temp->GetMyMinute();
				AddCourseToList(myMorningList, temp);
				if (myConnect->IsSatisfy(tempList, myMorningList, counter))
				{
					continue;
				}
				else
				{
					//temp = &(*(myMorningList->end() - 1));
					//tempList->push_back(*temp);
					//myMorningList->pop_back();
					//counter -= temp->GetMyMinute();
					RemoveCourseToTempList(myMorningList);
					continue;
				}
			}
			else
			{
				//temp = &(*(myMorningList->end() - 1));
				//tempList->push_back(*temp);
				//myMorningList->pop_back();
				//counter -= temp->GetMyMinute();
				TempListMakeToZero();
				RemoveCourseToTempList(myMorningList);
				continue;
			}
		}
		else
		{
			if (!myConnect->IsSatisfy(tempList, myMorningList, counter))
			{
				//CCourse* temp = ;
				//tempList->push_back(*temp);
				//myMorningList->pop_back();
				//counter -= temp->GetMyMinute();
				RemoveCourseToTempList(myMorningList);
				continue;
			}
		}
		if (counter == 180)
			break;
		else
		{
			RemoveCourseToTempList(myMorningList);
		}
			
	}
	*/

	/*
	CCourse* temp = GetOneCourse(myRandom->GetRandom(1, tempList->size()));
	if (temp)
	{
		myMorningList->push_back(*temp);
		counter += temp->GetMyMinute();
		if (MorningIsSatisfy() &&  myConnect->IsSatisfy(tempList, myMorningList, counter))
		{
			return;
		}
		else
		{
			if (MorningIsSatisfy())
			{
				GetMorningTrack(1);
			}
			else
			{
				temp = &(*(myMorningList->end() - 1));
				tempList->push_back(*temp);
				myMorningList->pop_back();
				counter -= temp->GetMyMinute();
				GetMorningTrack(1);
			}
			if (!myConnect->IsSatisfy(tempList, myMorningList, counter))
			{
				temp = &(*(myMorningList->end() - 1));
				tempList->push_back(*temp);
				myMorningList->pop_back();
				counter -= temp->GetMyMinute();
				GetMorningTrack(1);
			}
		}
		
	}
	else
	{
		temp = &(*(myMorningList->end() - 1));
		tempList->push_back(*temp);
		TempListMakeToZero();
		myMorningList->pop_back();
		counter -= temp->GetMyMinute();
		GetMorningTrack(1);
	}


	if (MorningIsSatisfy())
	{
		vector<CCourse>::iterator it = tempList->begin();
		if ((*tempList)[num - 1].GetMyMinute() == 0)
			(*tempList)[num - 1].SetMyMinute(35);
		myMorningList->push_back((*tempList)[num - 1]);
		counter += (*tempList)[num - 1].GetMyMinute();
		it += (num - 1);
		tempList->erase(it);
		GetMorningTrack(myRandom->GetRandom(1, tempList->size()));
	}
	else
	{
		if (!MorningIsSatisfy())
		{
			myMorningList->clear();
			tempList->clear();
			tempList = myCourse;
			GetMorningTrack(myRandom->GetRandom(1, tempList->size()));
		}
		if (myConnect->IsSatisfy(tempList, myMorningList, counter))
		{
			myMorningList->clear(); 
			tempList->clear();
			tempList = myCourse;
			GetMorningTrack(myRandom->GetRandom(1, tempList->size()));
		} 
	}
	*/
}
void CTrackManager::GetAfternoonTrack()
{
	while (1)
	{
		if (myCounter < 480)
		{
			if (myConnect->IsSatisfy(myTempList, myAfternoonList, myCounter))
			{
				if ((480 - myCounter) < 30)
				{
					vector<CCourse>::iterator it = myTempList->begin();
					while (it != myTempList->end())
					{
						if (it->GetMyID() == 19 || it->GetMyMinute() == 0)
						{
							(*it).SetMyMinute(480 - myCounter);
							it->SetMyWeight(1);
							CCourse *temp = new CCourse(*it);
							myAfternoonList->push_back(*temp);
							myCounter += temp->GetMyMinute();
							myTempList->erase(it);
							break;
						}
						it++;
					}
					if (480 == myCounter)
						continue;
				}
				CCourse* temp = GetOneCourse(myRandom->GetRandom(1, myTempList->size()));
				if (temp)
				{
					AddCourseToList(myAfternoonList, temp);
				}
				else
				{
					TempListMakeToZero();
					RemoveCourseToTempList(myAfternoonList);
				}
			}
			else
			{
				RemoveCourseToTempList(myAfternoonList);
			}
		}
		else if (myCounter > 480)
		{
			RemoveCourseToTempList(myAfternoonList);
		}
		else
		{
			if (myConnect->IsSatisfy(myTempList, myAfternoonList, myCounter))
			{
				break;
			}
			else
			{
				RemoveCourseToTempList(myAfternoonList);
			}
		}
	}


	/*
	while (1)
	{
		if (counter < 480)
		{
			if ((480 - counter) < 30)
			{
				vector<CCourse>::iterator it = tempList->begin();
				while (it != tempList->end())
				{
					if (it->GetMyID() == 19 || it->GetMyMinute() == 0)
					{
						(*it).SetMyMinute(480 - counter);
						it->SetMyWeight(1);
						CCourse *temp = new CCourse(*it);
						myMorningList->push_back(*temp);
						counter += temp->GetMyMinute();
						tempList->erase(it);
						break;
					}
					it++;
				}
				if (480 == counter)
					continue;
				else
					RemoveCourseToTempList(myMorningList);

			}
			CCourse* temp = GetOneCourse(myRandom->GetRandom(1, tempList->size()));
			if (temp)
			{
				AddCourseToList(myAfternoonList, temp);
				if (myConnect->IsSatisfy(tempList, myAfternoonList, counter))
				{
					continue;
				}
				else
				{
					RemoveCourseToTempList(myAfternoonList);
					continue;
				}
			}
			else
			{
				RemoveCourseToTempList(myAfternoonList);
				TempListMakeToZero();
				continue;
			}
		}
		else
		{
			if (!myConnect->IsSatisfy(tempList, myAfternoonList, counter))
			{
				RemoveCourseToTempList(myAfternoonList);
				continue;
			}
		}
		if (counter == 480)
			break;	
		else
			RemoveCourseToTempList(myAfternoonList);
	}
	*/


	/*
	if (AfternoonIsSatisfy())
	{
		vector<CCourse>::iterator it = tempList->begin();
		if ((*tempList)[num - 1].GetMyMinute() == 0)
			(*tempList)[num - 1].SetMyMinute(15);
		myAfternoonList->push_back((*tempList)[num - 1]);
		it += (num - 1);
		tempList->erase(it);
		GetAfternoonTrack(myRandom->GetRandom(1, tempList->size()));
	}
	else
	{
		if (!AfternoonIsSatisfy())
		{
			myAfternoonList->clear();
			tempList->clear();
			tempList = RemoveMorningList();
			GetAfternoonTrack(myRandom->GetRandom(1, tempList->size()));
		}
		if (myConnect->IsSatisfy(tempList, myAfternoonList, counter))
		{
			myAfternoonList->clear();
			tempList->clear();
			tempList = RemoveMorningList();
			GetAfternoonTrack(myRandom->GetRandom(1, tempList->size()));
		}
	}
	*/
}
/*

bool CTrackManager::MorningIsSatisfy()
{
	if (counter > 180)
		return false;

	if ((180 - counter) < 35 && counter != 180)
	{
		vector<CCourse>::iterator it = tempList->begin();
		while (it != tempList->end())
		{
			if (it->GetMyMinute() == 0 && it->GetMyID() != 19)
			{
				(*it).SetMyMinute(180 - counter);
				it->SetMyWeight(1);
				myMorningList->push_back(*it);
				counter += it->GetMyMinute();
				tempList->erase(it);
				return true;
			}	
			it++;
		}
	}
	//if (counter == 180)
		//return true;
	return true;
}
bool CTrackManager::AfternoonIsSatisfy()
{
	if (counter > 480)
		return false;

	return true;
}
*/

vector<CCourse>* CTrackManager::RemoveMorningList()
{
	myTempList = myCourse;
	vector<CCourse>::iterator tempIt = myTempList->begin();
	vector<CCourse>::iterator morningIt = myMorningList->begin();
	while (tempIt != myTempList->end())
	{
		while (morningIt != myMorningList->end())
		{
			if (tempIt->GetMyID() == morningIt->GetMyID())
			{
				myTempList->erase(tempIt);
				myTempList--;
			}
			morningIt++;
		}
		tempIt++;
	}
	return myTempList;
}

CCourse* CTrackManager::GetOneCourse(int num)
{
	bool hasCourse = false;
	for (int i = 0; i < myTempList->size(); i++)
	{
		if (myTempList->at(i).GetMyWeight() == 0)
		{
			hasCourse = true;
			break;
		}	
	}
	if (!hasCourse)
		return nullptr;

	int random = myRandom->GetRandom(0, myTempList->size() - 1);
	vector<CCourse>::iterator it = myTempList->begin() + random;
	if (it->GetMyWeight() == 0)
	{
		CCourse *course = new CCourse(myTempList->at(random));
		myTempList->erase(it);
		return course;
	}
	else
	{
		GetOneCourse(1);
	}
	return nullptr;
}
void CTrackManager::TempListMakeToZero()
{
	for (int i = 0; i < myTempList->size(); i++)
	{
		myTempList->at(i).SetMyWeight(0);
	}
	//cout << "ÖØÖÃ:" << endl;
}
void CTrackManager::AddCourseToList(vector<CCourse>* list, CCourse * element)
{
	CCourse* tempCourse = new CCourse(*element);
	if (tempCourse->GetMyMinute() == 0)
		(*tempCourse).SetMyMinute(30);
	tempCourse->SetMyWeight(1);
	myCounter += tempCourse->GetMyMinute();
	list->push_back(*tempCourse);
	//cout << "Ìí¼Ó:" << tempCourse->GetMyID() <<","<< tempCourse->GetMyMinute() <<  endl;
}
void CTrackManager::RemoveCourseToTempList(vector<CCourse>* list)
{
	if (list->size() == 0)
		return;
	CCourse* tempCourse = new CCourse(*(list->end() - 1));
	myCounter -= tempCourse->GetMyMinute();
	if (tempCourse->GetMyID() == 6 || tempCourse->GetMyID() == 19)
		tempCourse->SetMyMinute(0);
	myTempList->push_back(*tempCourse);
	list->pop_back();
	//cout << "É¾³ý:" << tempCourse->GetMyID() << "," << tempCourse->GetMyMinute() << endl;
}
void CTrackManager::test()
{
	vector<CCourse>::iterator it = myTempList->begin();
	while (it != myTempList->end())
	{
		if (it->GetMyID() == 1 || it->GetMyID() == 6 || it->GetMyID() == 17 || it->GetMyID() == 11)
		{
			it = myTempList->erase(it);
		}
		it++;
	}
	AddCourseToList(myMorningList, new CCourse("K", 11, 45));
	AddCourseToList(myMorningList, new CCourse("Q", 17, 30));
	AddCourseToList(myMorningList, new CCourse("F", 6, 30));
	AddCourseToList(myMorningList, new CCourse("A", 1, 60));
	myCounter = 195;
}

void CTrackManager::MergeList()
{
	for (int i = 0; i < myMorningList->size(); i++)
	{
		CCourse* tempCourse = new CCourse((*myMorningList)[i]);
		myTotalList->push_back(*tempCourse);
	}
	myTotalList->push_back(*(new CCourse("Lunch", 0, 60)));
	for (int i = 0; i < myAfternoonList->size(); i++)
	{
		CCourse* tempCourse = new CCourse((*myAfternoonList)[i]);
		myTotalList->push_back(*tempCourse);
	}
}