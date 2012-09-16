#include "algostuff.hpp"
using namespace std;

int main()
{
	deque<int> coll;

	INSERT_ELEMENTS(coll,1,6);
	PRINT_ELEMENTS(coll);

	// print all differences between elements
	adjacent_difference (coll.cbegin(), coll.cend(), 		// source
						 ostream_iterator<int>(cout," "));	// destination
	cout << endl;

	// print all sums with the predecessors
	adjacent_difference (coll.cbegin(), coll.cend(),		// source
						 ostream_iterator<int>(cout," "),	// destination
						 plus<int>());						// operation
	cout << endl;

	// print all products between elements
	adjacent_difference (coll.cbegin(), coll.cend(),		// source
						 ostream_iterator<int>(cout," "),	// destination
						 multiplies<int>());				// operation
	cout << endl;
}
