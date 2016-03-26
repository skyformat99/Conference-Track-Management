#pragma once
#include <string>
using namespace std;

class CCourse
{
public:
	CCourse();
	CCourse(string name, int id, int minute, int weight = 0);
	~CCourse();

	void SetMyName(string name);
	string GetMyName();

	void SetMyID(int id);
	int GetMyID();

	void SetMyMinute(int minute);
	int GetMyMinute();

	void SetMyWeight(int weight);
	int GetMyWeight();
private:
	string myName;
	int myID;
	int myMinute;
	int myWeight; // 权值 用于排序
};

