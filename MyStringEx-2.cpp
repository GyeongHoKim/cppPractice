#include <iostream>
#include <cstring>
#include "MyStringEx.h"

CMyStringEx::CMyStrinEx() {}
CMyStringEx::~CMyStringEx() {}

int CMyStringEx::Find(const char* pszParam)
{
    if(pszParam == NULL || GetString() == NULL)
        return -1;
        
    const char *pszResult = strstr(GetString(), pszParam);
    
    if(pszResult != NULL)
        return pszResult - GetString();
        
    return -1;
}

int CMyStringEx::SetString(const char* pszParam)
{
    CMyString::Release();
    
    int nResult;
    if(strcmp("멍멍이아들", pszParam) == 0)
        nResult = CMyString::SetString("착한 사람");
    else
        nResult = CMyString::SetString(pszParam);
        
    return nResult;
}