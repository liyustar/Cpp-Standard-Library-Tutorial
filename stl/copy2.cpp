#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iostream>
using namespace std;

template <typename T>
void printIter(T t)
{
	// for (auto elem : t) {
	typename T::iterator elem;
	for (elem=t.begin(); elem!=t.end(); ++elem) {
		cout << *elem << ' ';
	}
	cout << endl;
}

template <typename T>
inline void PRINT_ELEMENTS (const T& coll,
							const std::string& optstr="")
{
	std::cout << optstr;
	for (const auto& elem : coll) {
		std::cout << elem << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	list<int>	coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// copy the elements of coll1 into coll2 by appending them
	vector<int>	coll2;
	copy (coll1.cbegin(), coll1.cend(),	// source
			back_inserter(coll2));				// destination
	PRINT_ELEMENTS(coll2); 
	printIter(coll2);

	// copy the elements of coll1 into coll3 by inserting them at the front
	// - reverses the order of the elements
	deque<int> coll3;
	copy (coll1.cbegin(), coll1.cend(),	// source
			front_inserter(coll3));				// destination
	printIter(coll3);

	// copy the elements of coll1 into coll4
	// - only inserter that works for associative collections
	set<int> coll4;
	copy (coll1.cbegin(), coll1.cend(),	// source
			inserter(coll4, coll4.begin()));				// destination
	printIter(coll4);
	
}

