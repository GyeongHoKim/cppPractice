#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
	String(const char *str)
	{
		if(mystring == nullptr) {
			mystring = new char[strlen(str)];
			strncpy(mystring,str,strlen(str));
			len = strlen(str);
		}
		else {
			if(len < strlen(str)) {
				delete[] mystring;
				len = strlen(str);
				mystring = new char[len];
			}
		}
	}
	~String()
	{
		delete[] mystring;
	}
	
	operator char*() const
	{
		return mystring;
	}
private:
	char *mystring = nullptr;
	int len = 0;
};

int main()
{
	String s("Hello!");
	const char* sz = s;
	
	cout << s << endl;
	
	return 0;
}