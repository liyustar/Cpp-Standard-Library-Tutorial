#include <iostream>
#include <boost/regex.hpp>

std::string regstr = "a+";
boost::regex expression(regstr);
std::string testString = "aaa";

int main() {
	// ƥ������һ��a
	if( boost::regex_match(testString, expression) )
	{
		std::cout<< "Match" << std::endl;
	}
	else
	{
		std::cout<< "Not Match" << std::endl;
	}
}
