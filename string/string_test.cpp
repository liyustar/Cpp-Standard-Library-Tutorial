#include <iostream>
#include <string>
using namespace std;

string foo()
{
	string s1("dsfdsfkjlsdkjflaskdjflaksjflskjasdlkfjdsalkfjklsdhfhghhdhfdsjhfjksdh");
	string s2("dkjflaskdjflaksjflskjasdlkfjdsalkfjklsdhfhghhdhfdsjhfjksdh");
	string s = s1 + s2;
	return s;
}

int main()
{
	char *s = NULL;
	string s1(1,'s');
	// string s2(s1,1,3);
	string s2(3,'a');
	cout << s1 << endl;

	string s3;
	s3.reserve(10);
	s3 = "haha";
	cout << s3.capacity() << endl;
	cout << s3 << endl;
	s3.reserve(3);
	cout << s3.capacity() << endl;

	string str;
	while(getline(cin,str,':')){
		cout << str << '|' << endl;
	}

}
