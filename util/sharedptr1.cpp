#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#define MYCODE

int main()
{
	// two shared pointers representing two persons by their name
	shared_ptr<string> pNico(new string("nico"));
	shared_ptr<string> pJutta(new string("jutta"));
	// ERROR: shared_ptr<string> pNico = new string("nico");
	// OK:	  shared_ptr<string> pNico = make_shared<string>("nico"); 

	// capitalize person names
	(*pNico)[0] = 'N';
	pJutta->replace(0,1,"J");

	// put them multiple times in a container
	vector<shared_ptr<string>> whoMadeCoffee;
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);

	// print all elements
	for (auto ptr : whoMadeCoffee) {
		cout << *ptr << "  ";
	}
	cout << endl;

	// overwrite a name again
	*pNico = "Nicolai";

	// print all elements again
	for (auto ptr : whoMadeCoffee) {
		cout << *ptr << "  ";
	}
	cout << endl;

	// print some internal data
	cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;

#ifdef MYCODE

	// example 1  Alternatively
	shared_ptr<string> pNico1(new string("nico1"),
									[](string* p) {
										cout << "delete " << *p << endl;
										delete p;
									});

	// ERROR: pNico1 = new string("nico"); // no assignment for ordinary pointers
	pNico1.reset(new string("nico")); // OK
	shared_ptr<string> pNico2 = pNico1;

	// using shared pointers like ordinary pointers:
	(*pNico1)[0] = 'N';
	pNico1->replace(0,1,"n");

	pNico1 = nullptr;
	pNico2 = nullptr;

	cout << "finish exp 1" << endl;

	// example 2
	shared_ptr<int> p1(new int[10],
							[](int* p) {
								delete[] p;
							});
	shared_ptr<int> p2(new int[10],
							std::default_delete<int[]>());
	
	unique_ptr<int[]> p3(new int[10]); // OK
	// ERROR: shared_ptr<int[]> p4(new int[10]);
	
	std::unique_ptr<int,void(*)(int*)> p5(new int[10],
												[](int* p) {
													delete[] p;
												});
#endif

}

