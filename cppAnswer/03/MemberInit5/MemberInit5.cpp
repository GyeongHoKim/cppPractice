#include "stdafx.h"
#include <iostream>
using namespace std;

// ������ �ڵ�
class CTest
{
public:
	// ������ �ʱ�ȭ ����� �̿��� ��� �ʱ�ȭ
	CTest() { }

	// C++11���� ����� ���ÿ� ��� ������ �ʱ�ȭ�� �� �ִ�!
	int m_nData1 = 10;
	int m_nData2 = 20;

	void PrintData(void)
	{
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
	}
};

// ����� �ڵ�
int _tmain(int argc, _TCHAR* argv[])
{
	CTest t;
	t.PrintData();

	return 0;
}