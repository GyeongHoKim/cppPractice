#include <iostream>
#include <algorithm>

template<typename T>
class Copy
{
public:
    void operator() (T t, T s, int n)
    {
        for(int i = 0; i < 5; i++)
            *(t + i) = *(s + i);
    }
};

int main()
{
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5];
    Copy<int*> copy;
    copy(arr2, arr1, 5);
    
    for(int i = 0; i < 5; ++i) std::cout << arr2[i] << " ";

    return 0;
}