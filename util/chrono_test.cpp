#include <chrono>
#include <iostream>
#include <iomanip>
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

	chrono::milliseconds ms1;
	ms1 += twentySeconds + aDay;
	--ms1;
	ms1 *= 2;
	cout << ms1.count() << " ms" << endl;
	cout << chrono::nanoseconds(ms1).count() << " ns" << endl;

	// example 2
	chrono::milliseconds d(42);
	cout << d << endl;

	// example 3
	using namespace std::chrono;
	milliseconds ms(7255042);

	// split into hours, minutes, seconds, and milliseconds
	hours	hh = duration_cast<hours>(ms);
	minutes	mm = duration_cast<minutes>(ms % chrono::hours(1));
	seconds	ss = duration_cast<seconds>(ms % chrono::minutes(1));
	milliseconds msec
				= duration_cast<milliseconds>(ms % chrono::seconds(1));

	// and print durations and values:
	cout << "raw: " << hh << "::" << mm << "::"
					<< ss << "::" << msec << endl;
	cout << "     " << setfill('0') << setw(2) << hh.count() << "::"
									<< setw(2) << mm.count() << "::"
									<< setw(2) << ss.count() << "::"
									<< setw(3) << msec.count() << endl;

}
