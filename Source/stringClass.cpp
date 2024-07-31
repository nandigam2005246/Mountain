#include <iostream>
#include <istream>
#include <map>

using namespace std;

class String
{
public:
	//Default
	String()
	{
		str = nullptr;
		len = 0;
	}

	//Param
	String(const char* ch)
	{
		len = strlen(ch);
		str = new char[len + 1];
		strcpy(str, ch);
	}

	//Copy
	String(const String& ch)
	{
		this->len = ch.len;
		this->str = new char[len + 1];
		strcpy(str, ch.str);
		str[strlen(ch.str)] = '\0';
	}

	//Copy assignement
	String& operator=(String obj)
	{
		Swap(*this, obj);
		return *this;
	}
	void Swap(String& obj1, String& obj2)
	{
		std::swap(obj1.len, obj2.len);
		std::swap(obj1.str, obj2.str);
	}

	// move constructor
	String(String&& obj)
	{
		strcpy(str, obj.str);
		obj.str = nullptr;
	}	

	friend ostream& operator<<(ostream& out, const String& obj);
	//friend istream& operator>>(istream& in, const String& obj);
	friend istream& operator>>(istream& in, String& obj) {
		char* buff = new char[1000];
		memset(&buff[0], 0, sizeof(buff));
		in >> buff;
		obj = String{ buff };
		delete[] buff;
		return in;
	}
private:
	char* str;
	unsigned int len;
};


int main()
{
	String str1; // default constructor
	//String str2 = "Hello World"; //param constructor
	String str2;
	String str4;
	cin >> str4; //= "Hello World"; //param constructor
	cout << str4;
	//String str3(str2); // copy constructor
	//cout << str3;
	//cout << str3;

	std::map<std::string, int> names;
	names.emplace("Hello", 3);
	names.emplace("Hello1", 4);

	for (auto& name : names)
	{
		cout << name.first << endl;
		cout << name.second << endl;
	}
}

ostream& operator<<(ostream& out, const String& obj)
{
	out << obj.str;
	return out;
}
