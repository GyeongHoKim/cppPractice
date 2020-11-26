#include <iostream>
#include <functional> //plus<>, minus<> header
using namespace std;

struct Plus
{
	int operaotr() (int a, int b)
	{
		return a + b;
	}
};

struct Minus
{
	int operator() (int a, int b)
	{
		return a - b;
	}
};

int main()
{
	cout << Plus() (10, 20) << endl;
}