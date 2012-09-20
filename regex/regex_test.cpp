#include <iostream>
#include <boost/regex.hpp>

std::string regstr = "a+";
boost::regex expression(regstr);
std::string testString = "aaa";

int main() {
	// 匹配至少一个a
	if( boost::regex_match(testString, expression) )
	{
		std::cout<< "Match" << std::endl;
	}
	else
	{
		std::cout<< "Not Match" << std::endl;
	}
}
