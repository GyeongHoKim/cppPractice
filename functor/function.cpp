#include <iostream>
using namespace std;

struct FuncObject //equal to class
{
public:
	void operator() (int arg) const
	{
		cout << "inteer: " << arg << endl;
	}
};

void Print1(int arg)
{
	cout << "integer: " << arg << endl;
}

int main()
{
    void (*Print2)(int) = Print1;
    FuncObject Print3;

    Print1(10); // first, print integer with function
    Print2(10); // second, print integer with function pointer
    Print3(10); // third, print integer with function functor(equal to Print3.operator(10))

    return 0;
}