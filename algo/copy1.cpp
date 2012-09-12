#include "algostuff.hpp"
using namespace std;

int main()
{
	vector<string> coll1 = { "Hello", "this", "is", "an", "example" };
	list<string> coll2;

	// copy elements of coll1 into coll2
	// - use back inserter to insert instead of overwrite
	copy (coll1.cbegin(), coll1.cend(),		// source range
		  back_inserter(coll2));			// destination range

	// print elements of coll2
	// - copy elements to cout using an ostream iterator
	copy (coll2.cbegin(), coll2.cend(),		// source range
		  ostream_iterator<string>(cout," "));	// destination range
	cout << endl;

	// copy elements of coll1 into coll2 in reverse order
	// - now overwrite
	copy (coll1.crbegin(), coll1.crend(),	// source range
		  coll2.begin());					// destination range

	// print elements of coll2 again
	copy (coll2.cbegin(), coll2.cend(),		// source range
		  ostream_iterator<string>(cout," "));	// destination range
	cout << endl;
}
