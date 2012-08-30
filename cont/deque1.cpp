#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	// create empty deque of strings
	deque<string> coll;

	// insert several elements
	coll.assign (3, string("string"));
	coll.push_back("last string");
	coll.push_front("first string");

	// print elements separated by newlines
	copy (coll.cbegin(), coll.cend(),
			ostream_iterator<string>(cout,"\n"));
	cout << endl;

	// remove first and last element
	coll.pop_front();
	coll.pop_back();

	// insert "another" into every element but the first
	for (unsigned i=1; i<coll.size(); ++i) {
		coll.at(i) = "another " + coll.at(i);
	}

	// change size to four elements
	coll.resize (5, "resized string" );

	// print elements separated by newlines
	copy (coll.cbegin(), coll.cend(),
			ostream_iterator<string>(cout,"\n"));
}

