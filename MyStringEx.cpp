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

void CMyStringEx::OnSetString(char* pszData, int nLength)
{
    if(strcmp(pszData, "멍멍이아들") == 0)
        strcpy_s(pszData, sizeof(char)* (nLength + 1), "*착한아들*";
}