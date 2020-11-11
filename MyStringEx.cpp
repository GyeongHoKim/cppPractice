#include <iostream>
#include <cstring>
#include "MyStringEx.h"

CMyStringEx::CMyStrinEx() {}
CMyStringEx::~CMyStringEx() {}

CMyStringEx::CMyStringEx(const char* pszParam) : CMyString(const char* pszParam){};

int CMyStringEx::Find(const char* pszParam)
{
    if(pszParam == NULL || GetString() == NULL)
        return -1;
        
    const char *pszResult = strstr(GetString(), pszParam);
    
    if(pszResult != NULL)
        return pszResult - GetString();
        
    return -1;
}