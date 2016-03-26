#pragma once

#include "CCourse.h"
#include "CReader.h"
#include "CPrinter.h"
#include "CTrackManager.h"
using namespace std;

class CConferences
{
public:
	CConferences();
	~CConferences();
	void ProgreamStart();
	void PrintTrack();
	void SetJsonFilePath(const char* path);
private:
	CReader* myReader;
	CPrinter* myPrinter;
	CTrackManager* myTrackManager;
	vector<CCourse>* myPrinterList;
	const char* MyFilePath;
};

