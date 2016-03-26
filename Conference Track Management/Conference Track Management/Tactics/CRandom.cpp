#include "CRandom.h"

CRandom::CRandom()
{
	srand((int)time(NULL));
}

CRandom::~CRandom()
{
}
float CRandom::GetRandom(float start, float end)
{
	
	int pos, dis;
	if (start == end)
	{
		return start;
	}
	else if (start > end)
	{
		pos = end;
		dis = start - end + 1;
		return rand() % dis + pos;
	}
	else
	{
		pos = start;
		dis = end - start + 1;
		return rand() % dis + pos;
	}
}

/*
srand((unsigned)time(null));
(a, b) (rand() % (b - a + 1)) + a - 1
[a, b) (rand() % (b - a)) + a
(a, b](rand() % (b - a)) + a + 1
[a, b](rand() % (b - a + 1)) + a
*/
