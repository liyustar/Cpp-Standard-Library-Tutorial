#include <forward_list>
#include <iterator>
#include <iostream>
using namespace std;

void printLists (const forward_list<int>& l)
{
	cout << "list: ";
	copy (l.cbegin(), l.cend(), ostream_iterator<int>(cout," "));
	cout << endl << endl;
}

int main()
{
	forward_list<int> fwlist = { 1, 2, 3 };

	fwlist.insert_after (fwlist.begin(),	//position
						{ 77, 88, 99 } );
	 printLists(fwlist);
}

