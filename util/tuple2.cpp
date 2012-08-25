#include "printtuple.hpp"
#include <tuple>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	tuple <int,float,string> t(77, 1.1, "more light");
	cout << "io: " << t << endl;

	// has the following output:
	// 		io: [77,1.1,more light]
	// Here, the output expression
	// 		cout << t
	// calls
	// 		PRINT_TUPLE<0,3,Args...>::print(cout,t);
}
