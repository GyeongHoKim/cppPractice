#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nParam) : m_nData(nParam) { };
	~CTest() { }

	// ����� �޼���� ���� �� �����ߴ�.
	int GetData() const
	{
		// ��� ������ ���� ���� ���� ������ �� ���� ����.
		return m_nData;
	}

	int SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CTest a(10);
	cout << a.GetData() << endl;

	return 0;
}