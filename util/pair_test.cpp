#include <utility>
#include <functional>
#include <iostream>

template<typename T1, typename T2>
std::ostream & operator << (std::ostream & strm,
							const std::pair<T1, T2> & p)
{
	return strm << "[" << p.first << "," << p.second << "]";
}

int main()
{
	// example 1
	int i = 0;
	auto p1 = std::make_pair(std::ref(i), std::ref(i));
	++p1.first;
	++p1.second;

	std::cout << "i: " << i << std::endl;

	// example 2
	int a = 3, b = 4;
	auto p2 = std::make_pair(std::move(a), std::move(b));
	++p2.first;
	--p2.second;

	std::cout << "p2, a, b : " << p2
		<< "," << a << "," << b << std::endl; 

	// example 3
	std::pair<char, char> p3 = std::make_pair('x', 'y'); // paire of two chars

	char ch = 'l';
	std::tie(std::ignore, ch) = p3; // extract second value into c (ignore first one)

	std::cout << "p3: " << p3 << ", " << ch << std::endl;


	return 0;
}
