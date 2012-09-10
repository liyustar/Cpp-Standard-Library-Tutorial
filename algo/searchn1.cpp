#include "algostuff.hpp"
using namespace std;

// bool isPrime (int elem);
// bool binaryIsPrime (int elem1, int) {
// 		return isPrime(elem1);
// 	}


int main()
{
	deque<int> coll;

	coll = { 1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6 };
	PRINT_ELEMENTS(coll);

	// find three consecutive elements with value 7
	deque<int>::iterator pos;
	pos = search_n (coll.begin(), coll.end(),	// range
					3,							// count
					7);							// value

	// print result
	if (pos != coll.end()) {
		cout << "three consecutive elements with value 7 "
			 << "start with " << distance(coll.begin(), pos) + 1
			 << ". element" << endl;
	}
	else {
		cout << " no three consecutive elements with value 7 found"
			 << endl;
	}

	// find four consecutive odd elements
	pos = search_n (coll.begin(), coll.end(),	// range
					3,							// count
					7,							// value
					[](int elem, int value) {	// criterion
						return elem != value; //elem%2==1;
						});

	// pos = search_n_if (coll.begin(), coll.end(),
						// 4,
						// [](int elem) {
							// return elem%2!=0;
							// });
	
	// find four consecutive elements with value greater than 3
	pos = search_n (coll.begin(), coll.end(),	// range
					4, 							// count
					3,							// value
					greater<int>());			// criterion

	// print result
	if (pos != coll.end()) {
		cout << "first four consecutive odd elements are: ";
		for (int i=0; i<4; ++i, ++pos) {
			cout << *pos << ' ';
		}
	}
	else {
		cout << "no four consecutive elements with value > 3 dound";
	}

	cout << endl;
}
	
