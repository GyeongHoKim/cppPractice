#include <iostream>
using namespace std;

template<typename T>
class Queue
{
    T *buf;
    int len;
    int capacity;

public:
    explicit Queue(int cap = 100) : buf(0), len(0), capacity(cap)
    {
        buf = new T[capacity];
    }
    bool Push(T n);
    T Pop();
    bool Empty();
};

template<typename T>
bool Queue<T>::Push(T n)
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
T Queue<T>::Pop()
{
    T temp = buf[0];
    len--;
    buf++;
    return temp;
}

template<typename T>
bool Queue<T>::Empty()
{
    if(len) return false;
    else return true;
}

int main()
{
    Queue<int> q;

    q.Push(10);
    q.Push(20);
    q.Push(30);

    if(!q.Empty())
        cout << q.Pop() << endl;
    if(!q.Empty())
        cout << q.Pop() << endl;
    if(!q.Empty())
        cout << q.Pop() << endl;

    return 0;
}