#include "MyList.h"
#include "UserData.h"
#include <stdio.h>
#include <cstring>

CMyList::CMyList(void) {}

CMyList::~CMyList(void) {}

int CMyList::AddNewNode(const char *pszName, const char *pszPhone)
{
    CUserData *pNewUser = NULL;

    if(FindNode(pszName) != NULL)
        return 0;

    pNewUser = new CUserData;
    strcpy(pNewUser->szName, sizeof(pNewUser->szName), pszName);
    strcpy(pNewUser->szPhone, sizeof(pNewUser->szPhone), pszPhone);
}

void CMyList::PrintAll(void) {}
