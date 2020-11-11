#include <iostream>
#include <cstring>
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

    OnSetString(m_pszData, m_nLength);
    
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

int CMyString::operator==(const CMyString &rhs)
{
    if(m_pszData != NULL && rhs.m_pszData != NULL)
        if(strcmp(m_pszData, rhs.m_pszData) == 0)
            return 1;
            
    return 0;
}

int CMyString::operator!=(const CMyString &rhs)
{
    if(m_pszData != NULL && rhs.m_pszData != NULL)
        if(strcmp(m_pszData, rhs.m_pszData) == 0)
            return 0;
    
    return 1;
}

CMyString operator+(const char *pszParam, const CMyString &strParam)
{
    CMyString strResult(pszParam);
    strResult.Append(strParam.m_pszData);
    
    return strResult;
}

void CMyString::OnSetString(char* pszData, int nLength) {}