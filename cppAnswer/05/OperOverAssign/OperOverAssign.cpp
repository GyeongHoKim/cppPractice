#include "stdafx.h"
#include <iostream>
using namespace std;

// ������ �ڵ�
class CmyCMyData
{
public:
	explicit CmyCMyData(int nParam)
	{
		m_pnData = new int(nParam);
	}

	~CmyCMyData() { delete m_pnData; }

	operator int() { return *m_pnData; }

	// �ܼ� ���� ������ ���� ����
	void operator=(const CmyCMyData &rhs)
	{
		// ���� ����Ű�� �޸𸮸� �����ϰ�
		delete m_pnData;

		// ���� �Ҵ��� �޸𸮿� ���� �����Ѵ�.
		m_pnData = new int(*rhs.m_pnData);
	}

private:
	int *m_pnData = nullptr;
};

// ����� �ڵ�
int _tmain(int argc, _TCHAR* argv[])
{
	CmyCMyData a(0), b(5);
	a = b;
	cout << a << endl;

	return 0;
}