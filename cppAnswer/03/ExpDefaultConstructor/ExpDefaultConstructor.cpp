#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
public:
	// ����Ʈ ������ ����
	CTest(void);
	int m_nData = 5;
};

// Ŭ���� �ܺο��� ����Ʈ ������ ����
CTest::CTest(void) { }

int _tmain(int argc, _TCHAR* argv[])
{
	CTest a;
	cout << a.m_nData << endl;

	return 0;
}