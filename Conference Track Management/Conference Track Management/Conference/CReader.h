#pragma once
#include <string>
#include <vector>
#include "CCourse.h"
using namespace std;


class CReader
{
public:
	CReader();
	~CReader();
	void LoadCourses(string fileName);
	vector<CCourse>* GetCourses();

private:
	vector<CCourse>* myCourses;
	
};

