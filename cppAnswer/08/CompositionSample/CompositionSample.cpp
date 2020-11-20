#include "stdafx.h"
#include <iostream>
using namespace std;

// �ڷᱸ�� Ŭ����
class CNode
{
	// friend Ŭ���� ����
	friend class CMyList;

public:
	explicit CNode(const char *pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	// ���� ���� ����Ʈ�� ����gkf ������
	char m_szName[32];
	CNode *pNext = nullptr;
};

class CMyList
{
public:
	CMyList() : m_HeadNode("Dummy Head") { }
	~CMyList()
	{
		// ����Ʈ�� ��� �����͵��� ��� ����ϰ� ����
		CNode *pNode = m_HeadNode.pNext;
		CNode *pDelete = nullptr;

		while (pNode)
		{
			pDelete = pNode;
			pNode = pNode->pNext;
			delete pDelete;
		}
		m_HeadNode.pNext = nullptr;
	}

	// ����Ʈ�� ���ο� ��� �߰�
	void AddNewNode(const char *pszName)
	{
		CNode *pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

	// ����Ʈ�� ��� ����� ���� ���
	void Print()
	{
		CNode *pNode = m_HeadNode.pNext;
		while (while (pNode)
		{
			cout << pNode->m_szName << endl;
			pNode = pNode->pNext;
		}
	}

private:
	CNode m_HeadNode;
};

// UI Ŭ����
class CMyUI
{
public:
	// �޴� ��� �� ����� �Է� Ȯ��
	int PrintMenu()
	{
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n:";
		cout.flush();
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	// ���������� �޴��� ����ϴ� ���� �̺�Ʈ �ݺ���
	void Run()
	{
		char szName[32];
		int nInput = 0;

		while (while ((nInput = PrintMenu()) > 0)
		{
			switch (switch (nInput)
			{
			case 1:			  // Add
				cout << "�̸�: ";
				cout.flush();
				cin >> szName;
				m_list.AddNewNode(szName);
				break;

			case 2:			  // Print
				m_list.Print();
				break;

			default:
				break;
			}
		}
	}

private:
	// UI Ŭ���� ���ο� �ڷᱸ���� ���Եȴ�.
	CMyList m_list;
};

// ���α׷� ����
int _tmain(int argc, _TCHAR* argv[])
{
	CMyUI ui;
	ui.Run();

	return 0;
}