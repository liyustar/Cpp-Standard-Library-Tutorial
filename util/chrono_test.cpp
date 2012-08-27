#include <chrono>
#include <iostream>
using namespace std;

template <typename V, typename R>
ostream& operator << (ostream& s, const chrono::duration<V,R>& d)
{
	s << "[" << d.count() << " of " << R::num << "/"
									<< R::den << "]";
	return s;
}

int main()
{
	// example 1
	chrono::seconds twentySeconds(20);
	chrono::hours aDay(24);

	chrono::milliseconds ms;
	ms += twentySeconds + aDay;
	--ms;
	ms *= 2;
	cout << ms.count() << " ms" << endl;
	cout << chrono::nanoseconds(ms).count() << " ns" << endl;

	// example 2
	chrono::milliseconds d(42);
	cout << d << endl;
}
