#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(5, 10);
	for(vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	
	vector<int> v2(5);
	v2.push_back(10);
	for(vector<int>::size_type i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	
	return 0;
}