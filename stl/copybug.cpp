#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int main()
{
	list<int>	coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>	coll2;

	// RUNTIME ERROR:
	// - overwrites nonexisting elements in the destination
	copy (coll1.cbegin(), coll1.cend(),	// source
			coll2.begin());				// destination
	// ...
}
