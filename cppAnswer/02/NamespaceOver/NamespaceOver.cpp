#include "stdafx.h"
#include <iostream>
using namespace std;

// ����(����� ���Ҽ�)
void TestFunc(void) { cout << "::TestFunc()" << endl; }

namespace TEST
{
	// TEST ���ӽ����̽� �Ҽ�
	void TestFunc(void) {
		cout << "TEST::TestFunc()" << endl;
	}
}

namespace MYDATA
{
	// MYDATA ���ӽ����̽� �Ҽ�
	void TestFunc(void) {
		cout << "DATA::TestFunc()" << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestFunc();          // ������ ����
	::TestFunc();        // ����� ����
	TEST::TestFunc();
	MYDATA::TestFunc();

	return 0;
}