#include "algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;

	INSERT_ELEMENTS(coll,1,9);
	PRINT_ELEMENTS(coll);

	// process sum of elements
	cout << "sum: "
		 << accumulate (coll.cbegin(), coll.cend(),	// range
				 		0)							// initial value
		 << endl;

	// process sum o felements less 100
	cout << "sum: "
		 << accumulate (coll.cbegin(), coll.cend(),	// range
				 		-100)						// initial value
		 << endl;

	// process product of elements
	cout << "product: "
		 << accumulate (coll.cbegin(), coll.cend(),	// range
				 		1,							// initial value
						multiplies<int>())			// operation
		 << endl;

	// process product of elements (use 0 as initial value)
	cout << "product: "
		 << accumulate (coll.cbegin(), coll.cend(),	// range
				 		0,							// initial value
						multiplies<int>())			// operation
		 << endl;
}
