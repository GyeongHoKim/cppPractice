#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    vector<int>::iterator normal_iter = v.begin() + 3;
    vector<int>::reverse_iterator reverse_iter(normal_iter);
    
    cout << "normal iter value: " << *normal_iter << endl;
    cout << "reverse iter value: " << *reverse_iter << endl;
    cout << endl;
    
    for(vector<int>::iterator iter = v.begin(); iter != normal_iter; ++iter)
        cout << *iter << " ";
    cout << endl;
    
    for(vector<int>::reverse_iterator riter = reverse_iter; riter != v.rend(); ++riter)
        cout << *riter << " ";
    cout << endl;
    
    return 0;
}