#pragma once

class CMyString
{
public:
    CMyString();

    explicit CMyString(const char* pszParam);
    CMyString(const CMyString &rhs);
    CMyString(CMyString &&rhs);

private:
    char* m_pszData;
    int m_nLength;

public:
    int SetString(const char* pszParam);
    const char* GetString() const;
    int GetLength() const;
    int Append(const char* pszParam);
    void Release();

    CMyString& operator=(const CMyString &rhs);
    CMyString operator+(const CMyString &rhs);
    CMyString& operator+=(const CMyString &rhs);
    char operator[](int nIndex) const;
    char& operator[](int nIndex);
    int operator==(const CMyString &rhs);
    int operator!=(const CMyString &rhs);
    
    virtual void OnSetString(char* pszData, int nLength);
    friend CMyString operator+(const char *pzParam, const CMyString &strPara);
};