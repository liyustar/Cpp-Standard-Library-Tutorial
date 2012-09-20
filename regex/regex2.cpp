#include <string>
#include <boost/regex.hpp>
#include <iostream>
#include <iomanip>
using namespace std;
using namespace boost;

int main()
{
	string data = "XML tag: <tag-name>the value</tag-name>\\.";
	cout << "data:             " << data << endl << endl;

	smatch m;	// for returned details of the match
	bool found = regex_search (data,
							   m,
							   // regex("<(.*)>(.*)</(\\1)>"));
							   regex(R"(<(.*)>(.*)</(\1)>)"));

	// print match details:
	cout << "m.empty():        " << boolalpha << m.empty() << endl;
	cout << "m.size():         " << m.size() << endl;
	if (found) {
		cout << "m.str():          " << m.str() << endl;
		cout << "m.length():       " << m.length() << endl;
		cout << "m.position():     " << m.position() << endl;
		cout << "m.prefix().str(): " << m.prefix().str() << endl;
		cout << "m.suffix().str(): " << m.suffix().str() << endl;
		cout << endl;

		// iterating over all matches (using the match index):
		for (int i=0; i<m.size(); ++i) {
			cout << "m[" << i << "].str():       " << m[i].str() << endl;
			cout << "m.str(" << i << "):         " << m.str(i) << endl;
			cout << "m.position(" << i << "):    " << m.position(i) << endl;
		}
		cout << endl;

		// iterating over all matches (using iterators):
		cout << "matches:" << endl;
		for (auto pos = m.begin(); pos != m.end(); ++pos) {
			cout << " " << *pos << " ";
			cout << "(length: " << pos->length() << ")" << endl;
		}
	}
}

