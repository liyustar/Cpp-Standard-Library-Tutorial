#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

template <typename T>
void printIter(T t)
{
	// for (auto elem : t) {
	typename T::iterator elem;
	for (elem=t.begin(); elem!=t.end(); ++elem) {
		cout << *elem << ' ';
	}
	cout << endl;
}

int main()
{
	list<int>	coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>	coll2;

	// resize destination to have enough room for the overwriting algorithm
	coll2.resize (coll1.size());

	// copy elements from first into second collection
	// - overwrites existing elements in destination
	copy (coll1.cbegin(), coll1.cend(),	// source
			coll2.begin());				// destination

	printIter(coll2);

	// create third collection with enough room
	// - initial size is passed as parameter
	deque<int> coll3(coll1.size());

	// copy elements from first into third collection
	copy (coll1.cbegin(), coll1.cend(),	// source
			coll3.begin());				// destination

	printIter(coll3);
}

