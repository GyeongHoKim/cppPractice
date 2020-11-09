#include <iostream>
#include "MyString.h"

CMyString::CMyString() : m_pszData(NULL), m_nLength(0){}

CMyString::CMyString(const char *pszParam) : m_pszData(NULL), m_nLength(0)
{
    SetString(pszParam);
}

CMyString::CMyString(const CMyString &rhs) : m_pszData(NULL), m_nLength(0)
{
    this->SetString(rhs.GetString());
}

CMyString::~CMyString()
{
    Release();
}

int CMyString::SetString(const char* pszParam)
{
    Release();
    if(pszParam == NULL) return 0;

    int nLength = strlen(pszParam);

    if(nLength == 0) return 0;

    m_pszData = new char[nLength + 1];

    strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
    m_nLength = nLength;

    return nLength;
}

const char* CMyString::GetString() const
{
    return m_pszData;
}

int CMyString::GetLength() const
{
    return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
    if(pszParam == NULL) return 0;
    int nLenParam = strlen(pszParam);
    if(m_pszData == NULL) {
        SetString(pszParam);
        return m_nLength;
    }

    int nLenCur = m_nLength;
    char *pszResult = new char[nLenCur + nLenParam + 1];

    strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
    strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

    Release();
    m_pszData = pszResult;
    m_nLength = nLenCur + nLenParam;

    return m_nLength;
}

void CMyString::Releas()
{
    if(m_pszData != NULL) delete[] m_pszData;

    m_pszData = NULL;
    m_nLength = 0;
}

CMyString CMyString::operator+(const CMyString &rhs)
{
    CMyString strResult(m_pszData);
    strResult.Append(rhs.GetString());
    return strResult;
}

CMyString& CMyString::operator+=(const CMyString &rhs)
{
    this.Append(rhs.GetString());
    return *this;
}

char CMyString::operator[](int nIndex) const
{
    return m_pszData[nIndex];
}

char& CMyString::operator[](int nIndex)
{
    return m_pszData[nIndex];
}