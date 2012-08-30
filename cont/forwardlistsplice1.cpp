#include <forward_list>
#include "print.hpp"
#include "findbefore.hpp"
using namespace std;

int main()
{
	forward_list<int> l1 = { 1, 2, 3, 4, 5 };
	forward_list<int> l2 = { 97, 98, 99 };

	// find 3 in l1
	auto pos1=l1.before_begin();
	for (auto pb1=l1.begin(); pb1 != l1.end(); ++pb1, ++pos1) {
		if (*pb1 == 3) {
			break;	// found
		}
	}

	// find 99 in l2
	auto pos2=l2.before_begin();
	for (auto pb2=l2.begin(); pb2 != l2.end(); ++pb2, ++pos2) {
		if (*pb2 == 99) {
			break;	// found
		}
	}

	// 这句出错了，不知到为什么。。。。。。。。。。。。
	// splice 3 from l1 to l2 before 99
	// l1.splice_after(pos1, l2,	// destination
	// 		pos2);				// source
	l1.splice_after(l2.find_before(99), l2,
					l1.find_before(3));

	PRINT_ELEMENTS(l1,"l1: ");
	PRINT_ELEMENTS(l2,"l2: ");
}
