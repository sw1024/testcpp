/**
 * @file	testlimit.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-29
 */

#include <iostream>
#include <mutex>

int main()
{
	if (auto var{10}; var > 9) {
		std::cout<<var<<std::endl;
	} else {
		std::cout<<"hello"<<std::endl;

	}

	std::mutex mymutex;
	if (std::lock_guard<std::mutex> lg(mymutex); 10 > 9) {
		std::cout<<"hello 1"<<std::endl;

	}
	if (std::lock_guard<std::mutex> lg(mymutex); 10 > 9) {
		std::cout<<"hello world"<<std::endl;
	}

	return 0;
}
