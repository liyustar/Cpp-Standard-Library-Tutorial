#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#define MYCODE

class Person {
	public:
		string name;
		shared_ptr<Person> mother;
		shared_ptr<Person> father;
		vector<weak_ptr<Person>> kids; // weak pointer !!!

		Person (const string& n,
				shared_ptr<Person> m = nullptr,
				shared_ptr<Person> f = nullptr)
			: name(n), mother(m), father(f) {
			}

		~Person() {
			cout << "delete " << name << endl;
		}
};

shared_ptr<Person> initFamily (const string& name)
{
	shared_ptr<Person> mom(new Person(name+"'s mom"));
	shared_ptr<Person> dad(new Person(name+"'s dad"));
	shared_ptr<Person> kid(new Person(name,mom,dad));
	mom->kids.push_back(kid);
	dad->kids.push_back(kid);
	return kid;
}

int main()
{
	shared_ptr<Person> p = initFamily("nico");

	cout << "nico's family exists" << endl;
	cout << "- nico is shared " << p.use_count() << " times" << endl;
	cout << "- name of 1st kid of nico's mom: "
		<< p->mother->kids[0].lock()->name << endl;	// Note that by using weak pointers, we had to slightly modify the way we access the object referred to via a weak pointer.

	p = initFamily("jim");
	cout << "jim's family exists" << endl;

#ifdef MYCODE

	// example 1
	try {
		shared_ptr<string> sp(new string("hi"));	// create shared pointer
		weak_ptr<string> wp = sp;					// create weak pointer out of it
		sp.reset();									// release object of shared pointer
		cout << wp.use_count() << endl;				// prints: 0
		cout << boolalpha << wp.expired() << endl;	// prings: true
		shared_ptr<string> p(wp);					// whrows std:: bad_weak_ptr
	}
	catch (const std::exception& e) {
		cerr << "exception: " << e.what() << endl;	// prints: bad_weak_ptr
	}

	// example 2
	shared_ptr<Person> p1 = initFamily("nico");

	cout << "nico's family exists" << endl;
	cout << "- nico is shared " << p1.use_count() << " times" << endl;
	cout << "- name of 1st kid of nico's mom: "
		<< p1->mother->kids[0].lock()->name << endl;

	shared_ptr<Person> p2(p1);
	cout << "- nico is shared " << p1.use_count() << " times" << endl;

	p1 = initFamily("jim");
	cout << "- nico is shared " << p1.use_count() << " times" << endl;
	cout << "jim's family exists" << endl;
	

#endif

}
