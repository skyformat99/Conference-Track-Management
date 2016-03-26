#include "Conference\CConferences.h"
#include <iostream>
using namespace std;
int main()
{
	CConferences* conferences = new CConferences();

	conferences->ProgreamStart();
	
	conferences->PrintTrack();

	system("PAUSE");
	return 0;
}