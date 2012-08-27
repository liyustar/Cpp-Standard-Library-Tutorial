#include <chrono>
#include <iostream>
#include <thread>
#include "timepoint.hpp"

int main()
{
	auto tp1 = makeTimePoint(2010,01,01,00,00);
	std::cout << asString(tp1) << std::endl;

	auto tp2 = makeTimePoint(2011,05,23,13,44);
	std::cout << asString(tp2) << std::endl;

	// example 1
	for (int i=0; i<5; i++) {
		auto tp = std::chrono::system_clock::now();
		std::cout << asString(tp) << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
	
