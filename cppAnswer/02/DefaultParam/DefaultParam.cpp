#include "stdafx.h"
#include <iostream>

// nParam �Ű������� ����Ʈ ���� 10�̴�.
int TestFunc(int nParam = 10)
{
	return nParam;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// ȣ���ڰ� ���μ��� ������� �ʾ����Ƿ� ����Ʈ ���� �����Ѵ�.
	std::cout << TestFunc() << std::endl;

	// ȣ���ڰ� ���μ��� Ȯ�������Ƿ� ����Ʈ ���� �����Ѵ�.
	std::cout << TestFunc(20) << std::endl;

	return 0;
}