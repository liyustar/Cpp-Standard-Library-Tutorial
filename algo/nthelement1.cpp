#include "algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;

	INSERT_ELEMENTS(coll,3,7);
	INSERT_ELEMENTS(coll,2,6);
	INSERT_ELEMENTS(coll,1,5);
	INSERT_ELEMENTS(coll,2,3);
	PRINT_ELEMENTS(coll);

	// extract the four lowest elements
	nth_element (coll.begin(),		// beginning of range
				 coll.begin()+3,	// element that should be sorted correctly
				 coll.end());		// end of range

	// print them
	cout << "the four lowest elements are:  ";
	copy (coll.cbegin(), coll.cbegin()+4,
		  ostream_iterator<int>(cout," "));
	cout << endl;

	// extract the four highest elements
	nth_element (coll.begin(),		// beginning of range
				 coll.end()-4,	// element that should be sorted correctly
				 coll.end());		// end of range

	// print them
	cout << "the four highest elements are:  ";
	copy (coll.cend()-4, coll.cend(),
		  ostream_iterator<int>(cout," "));
	cout << endl;

	// extract the four highest elements (second version)
	nth_element (coll.begin(),		// beginning of range
				 coll.begin()+3,	// element that should be sorted correctly
				 coll.end(),		// end of range
				 greater<int>());	// sorting criterion
				 
	// print them
	cout << "the four highest elements are: ";
	copy (coll.cbegin(), coll.cbegin()+4,
		  ostream_iterator<int>(cout," "));
	cout << endl;
}
