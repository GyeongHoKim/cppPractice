#include "stdafx.h"
#include "MyString.h"

CMyString TestFunc(void)
{
	CMyString strTest("TestFunc() return");
	cout << strTest << endl;

	return strTest;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// �̸� ���� �ӽ� ��ü�� ���������.
	TestFunc();

	return 0;
}