#pragma once
#include <vector>
#include "CCourse.h"
#include "..\Tactics\CTacticsConnect.h"
#include "..\Tactics\CRandom.h"

using namespace std;

class CTrackManager
{
public:
	CTrackManager();
	~CTrackManager();

	void SetMyCourses(vector<CCourse>* list);
	vector<CCourse>* BuildTrack();

private:
	vector<CCourse>* myCourse;
	vector<CCourse>* myTempList;
	vector<CCourse>* myMorningList;
	vector<CCourse>* myAfternoonList;
	vector<CCourse>* myTotalList;
	CTacticsConnect* myConnect;
	CRandom* myRandom;
	int myCounter; //������ �ж�������
	
private:
	void GetMorningTrack();
	void GetAfternoonTrack();
	//bool MorningIsSatisfy();
	//bool AfternoonIsSatisfy();
	vector<CCourse>* RemoveMorningList();//�ѷ���
	CCourse* GetOneCourse(int);
	void TempListMakeToZero();
	void AddCourseToList(vector<CCourse>* , CCourse*);
	void RemoveCourseToTempList(vector<CCourse>*);
	void MergeList();

	void test();
};

