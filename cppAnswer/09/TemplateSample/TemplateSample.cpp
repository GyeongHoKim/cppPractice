#include "stdafx.h"
#include <iostream>
using namespace std;

// 'T'�� �ڷ����� �ȴ�.
template<typename T>
class CMyData
{
public:
	CMyData(T param) : m_Data(param) { }
	T GetData() const { return m_Data; }

	// ���Ŀ� ���� ��ȯ�� ����
	operator T () { return m_Data; }
	void SetData(T param) { m_Data = param; }

private:
	// T ������ ��� ���� ����
	T m_Data;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyData<int> a(5);
	cout << a << endl;
	CMyData<double> b(123.45);
	cout << b << endl;

	// ���ڿ��� �����ϱ� ���� �޸𸮸� ���� �Ҵ������� �ʴ´�.
	CMyData<char*> c("Hello");
	cout << c << endl;

	return 0;
}