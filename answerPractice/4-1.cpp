#include <iostream>

template<typename T>
class Copy
{
public:
    void operator() (T* t, T* s, int n)
    {
        for_each(t, t+n, arrcpy(t, s));
    }
    
    void arrcpy(T* t, T* s)
    {
        *t = *s;
    }
};

int main()
{
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5];
    Copy(arr2, arr1, 5);
    
    return 0;
}