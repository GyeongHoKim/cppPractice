#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int _x =0 , int _y =0 ):x(_x),y(_y) { }
    void Print( )const { cout << x <<',' << y << endl; }
    const Point& operator-- ( ) // 전위 --
    {
        x--;
        y--;
        return *this;
    }
    const Point operator--(int ) // 후위 --
    {  
        Point pt(x, y);
        --x;
        --y;
        return pt;
    }
};
void main( )
{
    Point p1(2,3), p2(2,3);
    Point result;

    result = --p1; // p1.operator--(); 와 같습니다.
    p1.Print();
    result.Print();

    result = p2--; // p2.operator--(0); 와 같습니다.   
    p2.Print();
    result.Print();
}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//    int x;
//    int y;
//public:
//    Point(int _x =0 , int _y =0 ):x(_x),y(_y) { }
//    void Print( ) const { cout << x <<',' << y << endl; }
//    bool operator== (const Point& arg) const
//    {
//      return x==arg.x && y==arg.y ? true : false;
//    }
//};
//void main( )
//{
//    Point p1(2,3), p2(5,5), p3(2,3);
//    
//    if( p1 == p2 )  // p1.operator== (p2) 와 같습니다.
//      cout << "p1 == p2" << endl;
//    if( p1 == p3 )  // p1.operator== (p3) 와 같습니다.
//      cout << "p1 == p3" << endl;
//}
