#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

#define MYCODE

int main()
{
	list<int> coll;

	// insert elements from 20 to 40
	for (int i=20; i<=40; ++i) {
		coll.push_back(i);
	}

	// find position of element with value 3
	// - there is none, so pos3 gets coll.end()
	auto pos3 = find (coll.begin(), coll.end(),		// range
						3);							// value

	// reverse the order of elements between found element and the end
	// - because pos3 is coll.end() it reverses an empty range
	reverse (pos3, coll.end());

	// find positions of values 25 and 35
	list<int>::iterator pos25, pos35;
	pos25 = find (coll.begin(), coll.end(),
					25);
	pos35 = find (coll.begin(), coll.end(),
					35);

	// print the maximum of the corresponding range
	// - note: including pos25 but excluding pos 35
	cout << "max: " << *max_element (pos25, pos35) << endl;

	// process the elements including the last position
	cout << "max: " << *max_element (pos25, ++pos35) << endl;

#ifdef MYCODE

	// exmaple 1
	auto pos30 = find (pos25, pos35, 30);
	if (pos30 == pos35) {
		cout << "30 is NOT in the subrange" << endl;
	}
	else {
		cout << "30 is in the subrange" << endl;
	}

	// example 2
	auto pos = find_if (coll.begin(), coll.end(),	// range
						[] (int i) {				// criterion
							return i == 25 || i == 35;
							});
	if (pos == coll.end()) {
		// no element with value 25 or 35 found
		// ...
	}
	else if (*pos == 25) {
		// element with value 25 comes first
		pos25 = pos;
		pos35 = find (++pos, coll.end(),
						35);
		// ...
	}
	else {
		// element with value 35 comes first
		pos35 = pos;
		pos25 = find (++pos, coll.end(),
						25);
		// ...
	}

#endif
}

