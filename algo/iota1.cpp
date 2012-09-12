#include "algostuff.hpp"
using namespace std;

int main()
{
	array<int,10> coll;

	iota (coll.begin(), coll.end(),	// destination
			42);					// start value

	PRINT_ELEMENTS(coll,"coll: ");
}
