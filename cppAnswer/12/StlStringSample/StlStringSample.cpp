#include "stdafx.h"

// string Ŭ������ ����ϱ� ���� ���
#include <string>

#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string strName;
	cout << "�̸�: ";
	cin >> strName;
	cout << "����� �̸��� " + strName + "�Դϴ�." << endl;

	return 0;
}