#include "stdafx.h"
#include <iostream>
using namespace std;

void TestFunc(const int &nParam)
{
	// ����� ���������� �Ϲ� ������ ����ȯ�ߴ�.
	int &nNewParam = const_cast<int &> (nParam);

	// ���� l-value�� �� �� �ִ�.
	nNewParam = 20;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nData = 10;

	// ����� ������ ���������� ���� ����ȴ�.
	TestFunc(nData);

	// ����� ���� ����Ѵ�.
	cout << nData << endl;

	return 0;
}