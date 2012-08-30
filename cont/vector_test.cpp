#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	time_t start, end;

	vector<int> v2(5);
	vector<int> vv(0);
	vv.pop_back();
	cout << v2.size() << " " << v2.capacity() << endl;
	for (int i=0; i<5; ++i) {
		v2[i] = i;
		cout << v2[i] << ' ';
	}
	cout << endl << endl;
	//vector<int>::iterator it = (vector<int>::iterator)v2.insert(++(v2.begin()), 3, 11);
	//v2.insert(it,4,22);
	for (int i=0; i<v2.size(); ++i) {
		cout << v2[i] << ' ';
	}
	cout << endl<< endl;



	vector<int> v;
	v.reserve(60);
	cout << v.size() << " " << v.capacity() << endl;
	cout << endl;

	int now = v.capacity();
	start = clock();
	for (int i=0; i<9999; ++i) {
		v.push_back(i);
		if (now != v.capacity()) {
			now = v.capacity();
			cout << now << endl;
		}
	}
	end = clock();
	cout << " test " << endl;
	cout << end - start << endl;	// 3770000	// 2380000
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	cout << " test 2 " << endl;
	v.reserve(99999);
	cout << v.size() << " " << v.capacity() << endl;

	cout << endl;
	start = clock();
	v.insert(v.begin(),3);
	end = clock();
	cout << end - start << endl;
	cout << v.size() << endl;

	cout << endl;
	start = clock();
	v.push_back(3);
	end = clock();
	cout << end - start << endl;
	cout << v.size() << endl;

}
