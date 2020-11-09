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
};