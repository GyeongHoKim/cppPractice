#include "stdafx.h"
#include <iostream>

// std ���ӽ����̽��� using ������ �����Ѵ�.
using namespace std;

namespace TEST
{
	int g_nData = 100;

	void TestFunc(void)
	{
		// cout�� ���ؼ� ������ ������ ���� �ʾƵ� �������.
		cout << "TEST::TestFunc()" << endl;
	}
}

// TEST ���ӽ����̽��� using ������ �Ѵ�.
using namespace TEST;

int _tmain(int argc, _TCHAR* argv[])
{
	// TestFunc()�� g_nData�� ���ؼ��� ���� ������ �� �ʿ䰡 ����.
	TestFunc();
	cout << g_nData << endl;

	return 0;
}