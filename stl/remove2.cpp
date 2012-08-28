#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	list<int> coll;

	// insert elements from 6 to 1 and 1 to 6
	for (int i=1; i<=6; ++i) {
		coll.push_front(i);
		coll.push_back(i);
	}

	// print all elements of the collection
	cout << "pre:  ";
	copy (coll.cbegin(), coll.cend(),		// source
			ostream_iterator<int>(cout," "));	// destination
	cout << endl;

	list<int>::iterator end = remove (coll.begin(), coll.end(), 3);

	// print all elements of the collection
	cout << "post: ";
	copy (coll.begin(), end,
			ostream_iterator<int>(cout," "));
	cout << endl;

	// print number of removed elements
	cout << "number of removed elements: "
		<< distance(end, coll.end()) << endl;

	// remove "removed" elements
	coll.erase (end, coll.end());

	// print all elements of the modified collection
	copy (coll.cbegin(), coll.cend(),
			ostream_iterator<int>(cout," "));
	cout << endl;

	// example 1
	coll.erase (remove(coll.begin(), coll.end(), 4), coll.end());
	copy (coll.cbegin(), coll.cend(),
			ostream_iterator<int>(cout," "));
	cout << endl;
}

