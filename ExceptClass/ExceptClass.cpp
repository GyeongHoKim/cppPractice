#include <iostream>
using namespace std;

class CMyException
{
    public:
        CMyException(int nCode, const char *pszMsg)
        {
            m_nErrorCode = nCode;
            strcpy_s(m_szMsg, sizeof(m_szMsg), pszMsg);
        }
        
        int GetErrorCode() const {return m_nErrorCode;}
        const char* GetMessage() const {return m_szMsg;}
        
    private:
        int m_nError;
        char m_szMsg[128];
};

int main(int argc, char* argv[])
{
    try
    {
        int nInput = 0;
        cout << "enter positive integer: ";
        cin >> nInput;
        
        if(nInput < 0)
        {
            CMyException exp(10, "you should enter POSITIVE integer");
            throw exp;
        }
    }
    
    catch(CMyException &exp)
    {
        cout << "ERROR CODE [" << exp.GetErrorCode() << "] " << exp.GetMessage() << endl;
    }
    
    return 0;
}