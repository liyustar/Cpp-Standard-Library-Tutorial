#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

int main()
{
	copy (istream_iterator<string>(cin),		// beginning of source
		  istream_iterator<string>(),			// end of source
		  ostream_iterator<string>(cout,"\n"));	// destination
}
