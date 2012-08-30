#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	cout << v.max_size() << endl;
	deque<int> d;
	cout << d.max_size() << endl;
}
