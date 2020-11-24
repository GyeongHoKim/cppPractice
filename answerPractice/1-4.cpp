#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
	String(const char *str)
	{
		mystring = new char[strlen(str)];
		strncpy(mystring,str,strlen(str));
		len = strlen(str);
	}
	~String()
	{
		delete[] mystring;
	}
	
	String& operator=(const char *str)
	{
		if(len < strlen(str)) {
			delete[] mystring;
			mystring = new char[strlen(str)];
		}
		len = strlen(str);
		strncpy(mystring,str,len);
		
		return *this;
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
	/*
	String s("Hello!");
	const char* sz = s;
	
	cout << s << endl;
	*/
	const char* sz = "Hello!";
	String s("Hi~!");
	cout << "s: " << s << endl;
	
	s = sz;
	cout << "s: " << s << endl;
	
	return 0;
}