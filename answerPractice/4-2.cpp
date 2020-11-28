#include <iostream>
using namespace std;

template<typename T>
class Stack
{
    T *buf;
    int len;
    int capacity;

public:
    explicit Stack(int cap = 100) : buf(0), len(0), capacity(cap)
    {
        buf = new T[capacity];
    }
    bool Push(T n);
    T Pop();
    bool Empty();
};

template<typename T>
bool Stack<T>::Push(T n)
{
    if(len > capacity)
    {
        delete [] buf;
        buf = new T[capacity + len];
    }
    buf[len++] = n;

    return true;
}

template<typename T>
T Stack<T>::Pop()
{
    len--;
    return buf[len];
}

template<typename T>
bool Stack<T>::Empty()
{
    if(len) return false;
    else return true;
}

int main()
{
    Stack<int> st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    if(!st.Empty())
        cout << st.Pop() << endl;
    if(!st.Empty())
        cout << st.Pop() << endl;
    if(!st.Empty())
        cout << st.Pop() << endl;

    return 0;
}