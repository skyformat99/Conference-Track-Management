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
	/*���ڳ������ԭ�����������
	��CCourse����Ա�������Ǹ�ֵ�ͷ��صĲ�����
	CTactics�����Ի��࣬��Ա�������麯������ʵ����������ɣ�
	CConferences���������̿��ƣ�
	CTrackConnect,���𽫲��Ժ��㷨������
	���ϲ����漰���㷨��������������Բ�����Ԫ���ԡ�
	*/
	CRandom* testandom = new CRandom(); //���������Լ�����ֲ����
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
	cout << "�������" << endl;

	CReader* testReader = new CReader(); //�����ļ���ȡ
	CPrinter* testPrinter = new CPrinter(); //���Դ�ӡʱ��

	vector<CCourse>* testList = new vector<CCourse>();

	testReader->LoadCourses("..\\Conference Track Management\\JsonFile\\Test_err.json");
	testList = testReader->GetCourses();
	if (testList->size() == 0)
		cout << "�ļ�����ֻҪ��һ����ʽ���Զ����ȡʧ��" << endl;

	testReader->LoadCourses("..\\Conference Track Management\\JsonFile\\Test.json");
	testList = testReader->GetCourses();
	testPrinter->SetMyCurrentPrintList(testList);
	testPrinter->Print();

	cout << "�������" << endl;

	CConferences* testConference = new CConferences(); //���Ի����
	testConference->SetJsonFilePath("..\\Conference Track Management\\JsonFile\\List.json");
	testConference->ProgreamStart();
	testConference->PrintTrack();
	
	cout << "�������" << endl;

	system("PAUSE");
	return 0;
}