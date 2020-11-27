#include <iostream>
using namespace std;

class Point
{
	int x; int y;
public:
	explicit Point(int _x = 0, int _y = 0):x(_x), y(_y) {}
	void Print() const {cout << x << ',' << y << endl;}
};

//general function template
template<typename T>
void Print(T a)
{
	cout << a << endl;
}

//special function template
template<>
void Print(Point a) //explicit code: void Print<Point>(Point a)
{
	cout << "Print special version: ";
	a.Print();
}

int main()
{
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);
	Print(d);
	Print(pt);

	return 0;
}
