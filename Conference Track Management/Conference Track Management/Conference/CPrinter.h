#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "CCourse.h"
using namespace std;

class CPrinter
{
public:
	CPrinter();
	~CPrinter();

	void SetMyCurrentPrintList(vector<CCourse>* list);
	void Print();
private:
	vector<CCourse>* myCurrentPrintList;
	int myTime;
	string TimeToString(int time);
};

