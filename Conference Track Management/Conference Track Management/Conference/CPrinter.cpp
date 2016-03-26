#include "CPrinter.h"
CPrinter::CPrinter():myTime(0)
{
	myCurrentPrintList = new vector<CCourse>();
	
}

CPrinter::~CPrinter()
{
	if (myCurrentPrintList)
	{
		myCurrentPrintList->clear();
		delete myCurrentPrintList;
	}
}
void CPrinter::SetMyCurrentPrintList(vector<CCourse>* list)
{
	myCurrentPrintList = list;
}
void CPrinter::Print()
{
	myTime = 0;
	cout << "会议安排如下：" << endl;
	cout << "09:00 ";
	for (int i = 0; i < myCurrentPrintList->size(); i++)
	{
		cout << myCurrentPrintList->at(i).GetMyName()
			<< " " << myCurrentPrintList->at(i).GetMyMinute() << "min" << endl;
		if (i != myCurrentPrintList->size() - 1)
			cout << TimeToString(myCurrentPrintList->at(i).GetMyMinute()) << " ";
	}
}
string CPrinter::TimeToString(int time)
{	
	myTime += time;
	stringstream buff;
	string strbuff;
	int hr = 9;
	int min = 0;
	int courseHr = myTime / 60;
	int courseMin = myTime % 60;
	if (hr + courseHr > 12)
	{
		hr = 0;
		buff << "0" << (hr + courseHr - 3) << ":";
		if (courseMin >= 10)
			buff << courseMin;
		else
			buff << "0" << courseMin;
	}
	else if ((hr + courseHr) >= 10)
	{
		buff << hr + courseHr << ":";
		if (courseMin >= 10)
			buff << courseMin;
		else
			buff << "0" << courseMin;
	}
	else
	{
		buff << "0" << (hr + courseHr) << ":";
		if (courseMin >= 10)
			buff << courseMin;
		else
			buff << "0" << courseMin;
	}
	buff >> strbuff;
	return strbuff;
}