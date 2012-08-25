#include <cstdio>
#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
using namespace std;

// container classes: map, multimap, unordered_map, and unordered_multimap. Use pairs to manage their elements.
#define MYCODE

class Foo {
	
	public:
		int xxxx, y;
		Foo (tuple<int, float>) {
			cout << "Foo::Foo(tuple)" << endl;
		}
		template <typename... Args>
			Foo (Args... args) {
				cout << "Foo::Foo(args...)" << endl;
			}
};


// generic output operator for pairs (limited solution)
template <typename T1, typename T2>
std::ostream& operator << (std::ostream& strm,
							const std::pair<T1, T2>& p)
{
	return strm << "[" << p.first << "," << p.second << "]" ;
}


int main()
{
	// create tuple t:
	tuple<int, float> t(1,2.22);

	// pass the tuple as a whole to the constructor of Foo:
	pair<int,Foo> p1(42, t);
	Foo f(t);	

	// pass the elements of the tuple to the constructor of Foo:
	pair<int,Foo> p2(piecewise_construct, make_tuple(42), t);

#ifdef MYCODE

	// code of pair
	cout << "My output data" << endl;

	pair<int, float>p3;
	cout << p3.first << " " << p3.second << endl;
	p3.first = 4;
	p3.second = 3.2;
	pair<int, float>p4;
	p4 = p3;
	cout << p4.first << " " << p4.second << endl;

	get<0>(p4) = 2;
	cout << p4.first << " " << p4.second << endl;

	// generic output operator for pairs (limited solution)
	cout << p4.first << endl;

	// code of tuple
	// cout << tuple_size<IntFloatPair>::v
	

#endif
}

