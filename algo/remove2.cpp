#include "algostuff.hpp"
using namespace std;
using namespace std::placeholders;

int main()
{
	list<int> coll1;

	INSERT_ELEMENTS(coll1,1,6);
	INSERT_ELEMENTS(coll1,1,9);
	PRINT_ELEMENTS(coll1);

	// print elements without those having the value 3
	remove_copy(coll1.cbegin(), coll1.cend(),	// source
				ostream_iterator<int>(cout," "),	// destination
				3);								// removed value
	cout << endl;
	PRINT_ELEMENTS(coll1);

	// print elements without those having a value greater than 4
	remove_copy_if(coll1.cbegin(), coll1.cend(), 	// source
				   ostream_iterator<int>(cout," "),	// destination
				   [] (int elem) {		// criterion for elements NOT copied
				   		return elem>4;
						});
	cout << endl;

	// copy all elements not less than 4 into a multiset
	multiset<int> coll2;
	remove_copy_if(coll1.cbegin(), coll1.cend(),	// source
				   inserter(coll2,coll2.end()),		// destination
				   bind(less<int>(),_1,4));			// elements NOT copied
	PRINT_ELEMENTS(coll2);
}
