#include <iostream>
#include <algorithm>
using namespace std;

struct Functor1
{
	void operator() (int n)
	{
		cout << n << " ";
	}
};

struct Functor2
{
	void operator() (int n)
	{
		cout << n*n << " ";
	}
};

struct Functor3
{
	void operator() (int n)
	{
		cout << "integer : " << n << endl;
	}
};

int main()
{
	int arr[5] = {10, 20, 30, 40, 50};
	
	for_each(arr, arr+5, Functor1());
	
	cout << endl << endl;
	for_each(arr, arr+5, Functor2());
	
	cout << endl << endl;
	for_each(arr, arr+5, Functor3());
	
	return 0;
}