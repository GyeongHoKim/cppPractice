#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	{
		// ���� ������ ����� ��� ��ü�� �ڵ����� �Ҹ��Ѵ�.
		auto_ptr<CMyData> ptrTest(new CMyData);
	}

	cout << "******End******" << endl;

	return 0;
}