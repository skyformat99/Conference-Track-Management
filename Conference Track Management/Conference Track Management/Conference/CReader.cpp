#include <fstream>
#include "CReader.h"
#include "..\JsonSDK\json.h"

CReader::CReader()
{
	myCourses = new vector<CCourse>();
}

CReader::~CReader()
{
	if (myCourses)
	{
		myCourses->clear();
		delete myCourses;
	}
		
}
void CReader::LoadCourses(string fileName)
{
	Json::Reader reader;
	Json::Value root;
	ifstream fileHandle;

	//¶ÁÈ¡ÎÄ¼þ
	fileHandle.open(fileName.data(), ios::binary);
	if (reader.parse(fileHandle, root))
	{
		int itemSize = root["Courses"].size();
		for (int i = 0; i < itemSize; i++)
		{
			string name = root["Courses"][i]["Name"].asString();
			int id = root["Courses"][i]["ID"].asInt();
			int min = root["Courses"][i]["Minute"].asInt();
			myCourses->push_back(*(new CCourse(name, id, min)));
		}
	}
	fileHandle.close();
}
vector<CCourse>* CReader::GetCourses()
{
	return myCourses;
}