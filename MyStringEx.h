#pragma once

class CMyStringEx : public CMyString
{
public:
    CMyStringEx();
    ~CMyStringEx();
    int Find(const char* pszParam);
};