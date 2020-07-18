/**
 * @file testlock.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-08-26
 */

#include <mutex>
#include <chrono>
#include <iostream>

int main()
{
	std::mutex datalock;

	//constexpr auto len = 4 * 1024;
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	for (int i = 0; i < 10000000; i++) {
		std::lock_guard<std::mutex> mlock(datalock);
		//auto ptr = new char[len];
		//delete [] ptr;
		//datalock.lock();
		//datalock.unlock();
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()<<"us"<<std::endl;

	return 0;
	 
}
