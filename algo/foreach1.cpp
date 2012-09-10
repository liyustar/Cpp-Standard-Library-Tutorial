#include "algostuff.hpp"
using namespace std;

void print (int elem)
{
	cout << elem << ' ';
}

int main()
{
	vector<int> coll;

	INSERT_ELEMENTS(coll,1,9);

	// call print() for each element
	
	// example 1
	for_each (coll.cbegin(), coll.cend(),	// range
			  [] (int elem) {
			  		cout << elem << ' ';
					});
	cout << endl;
	
	// example 2
	for_each (coll.cbegin(), coll.cend(),
			  print);
	cout << endl;

	// example 3
	// C++11
	for (auto elem : coll) {
		cout << elem << ' ';
	}
	cout << endl;
}
