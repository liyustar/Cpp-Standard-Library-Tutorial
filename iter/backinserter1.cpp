#include <vector>
#include <algorithm>
#include <iterator>
#include "print.hpp"
using namespace std;

int main()
{
	vector<int> coll;

	// create back inserter for coll
	// - inconvenient way
	back_insert_iterator<vector<int> > iter(coll);
	
	// insert elements with the usual iterator interface
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;
	iter++;
	PRINT_ELEMENTS(coll);

	// create back insert and insert elements
	// - convenient way
	back_inserter(coll) = 44;
	back_inserter(coll) = 55;
	PRINT_ELEMENTS(coll);

	vector<int>::iterator pos = coll.begin();
	cout << *pos << endl;

	vector<int> coll2(coll);
	PRINT_ELEMENTS(coll2);

	// use  back insert to append all elements again
	// - reserve enough memory to avoid reallocation
//	coll.reserve(2*coll.size());
	for (int i=0; i<4; ++i) {
	copy (coll.begin(), coll.end(),
			back_inserter(coll));
	cout << coll.capacity() << endl;
	}

	PRINT_ELEMENTS(coll);
	cout << *pos << endl;
}	
