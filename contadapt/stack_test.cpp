#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<pair<string,string>> st;

	auto p = make_pair("hello","world");
	st.push(move(p));

	st.emplace("nico","josuttis");

	while (!st.empty()) {
		cout << st.top().first << ' ';
		cout << st.top().second << endl;
		st.pop();
	}
	cout << endl;
}
