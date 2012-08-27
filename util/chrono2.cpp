#include <chrono>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

std::string asString (const std::chrono::system_clock::time_point& tp)
{
	// convert to system time:
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	std::string ts = std::ctime(&t);	// convert to calendar time
	ts.resize(ts.size()-1);				// skip trailing newline
	return ts;
}

int main()
{
	// define type for durations that represent day(s):
	typedef chrono::duration<int,ratio<3600*24>> Days;
	
	// process the epoch of this system clock
	chrono::time_point<chrono::system_clock> tp;
	cout << "epoch:     " << asString(tp) << endl;

	// add one day, 23 hours, and 55 minutes
	tp += Days(1) + chrono::hours(23) + chrono::minutes(55);
	cout << "later:     " << asString(tp) << endl;

	// process difference from epoch in minutes and days:
	auto diff = tp - chrono::system_clock::time_point();
	cout << "diff:      "
		<< chrono:: duration_cast<chrono::minutes>(diff).count()
		<< " minute(s)" << endl;
	Days days = chrono::duration_cast<Days>(diff);
	cout << "diff:      " << days.count() << " day(s)" << endl;

	// subtract one year (hoping it is valid and not a leap year)
	tp -= chrono::hours(24*365);
	cout << "-1 year:   " << asString(tp) << endl;

	// subtract 50 years (hoping it is valid and ignoring leap years)
	tp -= chrono::duration<int,ratio<3600*24*365>>(50);
	cout << "-50 years: " << asString(tp) << endl;

	// subtract 50 years (hoping it is valid and ignoring leap years)
	tp -= chrono::duration<int,ratio<3600*24*365>>(50);
	cout << "-50 years: " << asString(tp) << endl;
}
