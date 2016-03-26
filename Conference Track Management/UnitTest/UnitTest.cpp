#include <iostream>
#include <vector>
#include "..\Conference Track Management\Tactics\CRandom.h"
#include "..\Conference Track Management\Tactics\CRandom.cpp"
#include "..\Conference Track Management\Tactics\CTacticsConnect.cpp"
#include "..\Conference Track Management\Tactics\CTimeLimit.cpp"
#include "..\Conference Track Management\Tactics\CTactics.cpp"
#include "..\Conference Track Management\Conference\CReader.h"
#include "..\Conference Track Management\Conference\CReader.cpp"
#include "..\Conference Track Management\Conference\CPrinter.h"
#include "..\Conference Track Management\Conference\CPrinter.cpp"
#include "..\Conference Track Management\Conference\CCourse.h"
#include "..\Conference Track Management\Conference\CCourse.cpp"
#include "..\Conference Track Management\Conference\CConferences.h"
#include "..\Conference Track Management\Conference\CConferences.cpp"
#include "..\Conference Track Management\Conference\CTrackManager.cpp"

using namespace std;

int main()
{
	/*由于程序设计原因，许多类的设计
	如CCourse，成员函数都是赋值和返回的操作；
	CTactics，策略基类，成员函数是虚函数具体实现由子类完成；
	CConferences，负责流程控制；
	CTrackConnect,负责将策略和算法关联。
	以上并不涉及到算法的输入输出，所以不做单元测试。
	*/
	CRandom* testandom = new CRandom(); //测试区间以及随机分布情况
	int a[10] = { 0 };
	const int MAX = 10000000;
	for (int i = 0; i < MAX; i++)
	{
		switch ((int)(testandom->GetRandom(0, 9)))
		{
		case 0: a[0]++; break;
		case 1: a[1]++; break;
		case 2: a[2]++; break;
		case 3: a[3]++; break;
		case 4: a[4]++; break;
		case 5: a[5]++; break;
		case 6: a[6]++; break;
		case 7: a[7]++; break;
		case 8: a[8]++; break;
		case 9: a[9]++; break;
		}
	}
	for (int i = 0; i != 10; i++)
	{
		cout << i << ": " << double(a[i]) / MAX * 100 << "%" << endl;
		
	}
	cout << "测试完毕" << endl;

	CReader* testReader = new CReader(); //测试文件读取
	CPrinter* testPrinter = new CPrinter(); //测试打印时间

	vector<CCourse>* testList = new vector<CCourse>();

	testReader->LoadCourses("..\\Conference Track Management\\JsonFile\\Test_err.json");
	testList = testReader->GetCourses();
	if (testList->size() == 0)
		cout << "文件内容只要有一处格式不对都会读取失败" << endl;

	testReader->LoadCourses("..\\Conference Track Management\\JsonFile\\Test.json");
	testList = testReader->GetCourses();
	testPrinter->SetMyCurrentPrintList(testList);
	testPrinter->Print();

	cout << "测试完毕" << endl;

	CConferences* testConference = new CConferences(); //测试会议表
	testConference->SetJsonFilePath("..\\Conference Track Management\\JsonFile\\List.json");
	testConference->ProgreamStart();
	testConference->PrintTrack();
	
	cout << "测试完毕" << endl;

	system("PAUSE");
	return 0;
}