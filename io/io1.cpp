#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	double x, y;	// operands

	// print header string
	cout << "Multiplication of two floating point values" << endl;

	// read first operand
	cout << "first operand:  ";
	if (! (cin >> x)) {
		// input errror
		// => error message and exit program with error status
		cerr << "error while reading the first floating value"
			 << endl;
		return EXIT_FAILURE;
	}

	// read second operand
	cout << "second operand: ";
	if (! (cin >> y)) {
		// input error
		// => error message and exit program with error status
		cerr << "error while reading the second floating value"
			 << endl;
		return EXIT_FAILURE;
	}

	// print operands and result
	cout << x << " times " << y << " equals " << x * y << endl;
}
