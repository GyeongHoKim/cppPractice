#include <iostream>
using namespace std;

template<typename T, int nSize>
class CMyArray
{
public:
    CMyArray() {m_pData = new T[nSize];}
    ~CMyArray() {delete[] m_pData;}
    
    T& operator[](int nIndex)
    {
        if(nIndex < 0 || nIndex >= nSize) {
            cout << "ERROR: access beyond the boundary" << endl;
            exit(1);
        }
        
        return m_pData[nIndex];
    }
    
    T& operator[](int nIndex) const {return operator[](nIndex);}
    
    int GetSize() {return nSize;}
    
private:
    T *m_pData = nullptr;
};

int main(int argc, char* argv[])
{
    CMyArray<int, 3> arr;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    for(int i = 0; i < 3; ++i)
        cout << arr[i] << endl;
        
    return 0;
}