#include "CConferences.h"


CConferences::CConferences()
{
	myReader = new CReader();
	myPrinter = new CPrinter();
	myTrackManager = new CTrackManager();
	myPrinterList = new vector<CCourse>();
	MyFilePath = "JsonFile/List.json";
}

CConferences::~CConferences()
{
	if (myReader)
		delete myReader;
	if (myPrinter)
		delete myPrinter;
	if (myTrackManager)
		delete myTrackManager;
	if (myPrinterList)
	{
		myPrinterList->clear();
		delete myPrinterList;
	}
		
}

void CConferences::ProgreamStart()
{
	myReader->LoadCourses(MyFilePath);
	myTrackManager->SetMyCourses(myReader->GetCourses());
	
}
void CConferences::PrintTrack()
{
	myPrinterList = myTrackManager->BuildTrack();
	myPrinter->SetMyCurrentPrintList(myPrinterList);
	myPrinter->Print();
}
void CConferences::SetJsonFilePath(const char* path)
{
	MyFilePath = path;
}