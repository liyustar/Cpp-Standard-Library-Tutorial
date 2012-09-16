#include "algostuff.hpp"
using namespace std;

int main()
{
	vector<int> coll;

	INSERT_ELEMENTS(coll,1,9);

	// rotate one element to the left
	rotate (coll.begin(),		// beginning of range
			coll.begin() + 1,	// new first element
			coll.end());		// end of range
	PRINT_ELEMENTS(coll,"one left:   ");

	// rotate two element to the right
	rotate (coll.begin(),		// beginning of range
			coll.end() - 2,		// new first element
			coll.end());		// end of range
	PRINT_ELEMENTS(coll,"two right:  ");

	// rotate so that element with value 4 is the beginning
	rotate (coll.begin(),						// beginning of range
			find(coll.begin(), coll.end(), 4),	// new first element
			coll.end());						// end of range
	PRINT_ELEMENTS(coll,"4 first:    ");
}

