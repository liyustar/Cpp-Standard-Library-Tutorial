#include "algostuff.hpp"
using namespace std;

// function object that adds the value with which it is initialized
template <typename T>
class AddValue {
	private:
		T theValue;	// value to add
	public:
		// constructor initializes the value to add
		AddValue (const T& v) : theValue(v) {
		}

		// the function call for the element adds the value
		void operator () (T& elem) const {
			elem += theValue;
		}
};

int main()
{
	vector<int> coll;

	INSERT_ELEMENTS(coll,1,9);

	// add 10 to each element
	for_each (coll.begin(), coll.end(),
			  [](int& elem){
			  		elem += 10;
					});
	PRINT_ELEMENTS(coll);

	// add value offirst element to each element
	for_each (coll.begin(), coll.end(),
			  [=/*&*/](int& elem){
			  		elem += *coll.begin();
					});
	PRINT_ELEMENTS(coll);

	for_each (coll.begin(), coll.end(),
			  AddValue<int>(10));
	PRINT_ELEMENTS(coll);

	for_each (coll.begin(), coll.end(),
			  AddValue<int/*&*/>(*coll.begin()));
	PRINT_ELEMENTS(coll);
}

