#include "algostuff.hpp"
using namespace std;
using namespace std::placeholders;

int main()
{
	list<int> coll;

	INSERT_ELEMENTS(coll,2,6);
	INSERT_ELEMENTS(coll,4,9);
	PRINT_ELEMENTS(coll);

	// print all elements with value 5 replaced with 55
	replace_copy (coll.cbegin(), coll.cend(),		// source
				  ostream_iterator<int>(cout," "),	// destination
				  5,
				  55);
	cout << endl;

	// print all elements with a value less than 5 replaced with 42
	replace_copy_if (coll.cbegin(), coll.cend(),		// source
				  ostream_iterator<int>(cout," "),	// destination
				  bind(less<int>(),_1,5),			// replacement criterion
				  42);
	cout << endl;

	// print each element while each odd element is replaced with 0
	replace_copy_if (coll.cbegin(), coll.cend(),	// source
					 ostream_iterator<int>(cout," "),	// destination
					 [](int elem) {
					 	return elem%2!=0;
						},
					0);
	cout << endl;
}
