#include <tuple>
#include <iostream>
#include <complex>
#include <string>
#include <functional> // C++11 ref() and cref()
using namespace std;

#define MYCODE

int main()
{
	// create a four-element tuple
	// - elements are initialized with default value (0 for fundamental types)
	tuple<string, int, int, complex<double>> t;

	// create and initialize a tuple explicitly
	tuple<int, float, string> t1(41, 6.3, "nico");

	// "iterate" over elements:
	cout << get<0>(t1) << " ";
	cout << get<1>(t1) << " ";
	cout << get<2>(t1) << " ";
	cout << endl;

	// create tuple with make_tuple()
	// - auto declares t2 with type of right-hand side
	// - thus, type of t2 is tuple
	auto t2 = make_tuple(22, 44, "nico");

	// assign second value in t2 to t1
	get<1>(t1) = get<1>(t2);
	
	// "iterate" over elements:
	cout << get<0>(t1) << " ";
	cout << get<1>(t1) << " ";
	cout << get<2>(t1) << " ";
	cout << endl;

	// comparison and assignment
	// - including type conversion from tuple<int,int,const char*>
	// to tuple<int,float,string>
	if (t1 < t2) { // compares value for value
		t1 = t2;   // OK, assigns
	}


#ifdef MYCODE

	// example 1
	string s;
	int a;
	tuple<string&, int&> t3(s, a); // first element of tuple t refers to s

	get<0>(t3) = "hello";
	get<1>(t3) = 3;

	cout << s << ", " << a << endl;
	// out: hello, 3
	
	// example 2
	auto t4 = make_tuple(ref(s), ref(a));

	get<0>(t4) = "star";
	get<1>(t4) = 9;

	cout << s << ", " << a << endl;
	// out: star, 9

	// example 3
	tuple<int,float,string> t5(77, 1.1, "more light");
	int i;
	float f;
	// assign values of t to i, f, ane s:
	make_tuple(ref(i), ref(f), ref(s)) = t5;
	cout << "t5: " << i << ", " << f << ", " << s << endl;

	tuple<int,float,string> t6(11, 3.3, "bye bye");
	std::tie(i, std::ignore, s) = t6;
	cout << "t6: " << i << ", " << f << ", " << s << endl;
	
	// example 4
//	typename std::tuple<int,float,std::string> TupleType;
//	cout << "tuple_size, _type, _cat: " <<
//		std::tuple_size<TupleType>::vaiue << ", " << // yields 3
//		std:: tuple_element<1, TupleType>::type <<  endl; // yields float



#endif
}
