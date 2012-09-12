#include <cstdlib>
#include "algostuff.hpp"
using namespace std;

int gen() {
	return rand() % 100;
}

int main()
{
	list<int> coll;

	// insert five random numbers
	generate_n (back_inserter(coll),	// beginning of destination range
				5,						// count
				gen);					// new value generator
	PRINT_ELEMENTS(coll);

	// overwrite with five new random numbers
	generate (coll.begin(), coll.end(),	// destination range
			  gen);					// new value generator
	PRINT_ELEMENTS(coll);
}
