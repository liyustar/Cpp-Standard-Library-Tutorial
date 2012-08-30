#include <forward_list>
#include "print.hpp"
#include "findbefore.hpp"
using namespace std;

int main()
{
	forward_list<int> list = { 1, 2, 3, 4, 5, 97, 98, 99 };

	// find the position before the first even element
	auto posBefore = list.before_begin();
	for (auto pos=list.begin(); pos!=list.end(); ++pos, ++posBefore) {
		if (*pos % 2 == 0) {
			break;	// element found
		}
	}

	// find the position before the first even element
	posBefore = find_before_if(list.before_begin(), list.end(),
			[] (int i) {
				return i%4==0;
				});

	// and insert a new element in front of the first even element
	list.insert_after(posBefore, 42);
	PRINT_ELEMENTS(list);
}
