/**
 * @file testthread.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-08-17
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;

void print_thread_id(int id)
{
	mtx.lock();
	std::lock_guard<std::mutex> lock(mtx, std::adopt_lock);
	std::cout<<"thread#"<<id<<std::endl;

}

void printnum(int num)
{
	while(1) {
		std::cout<<"threadnum:"<<num<<std::endl;
		//std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1));
		break;
	}
}

int main()
{
	/*
	std::thread threads[10];
	for (int i = 0; i < 10; i++) {
		threads[i] = std::thread(print_thread_id, i + 1);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	for (auto& it : threads) {
		it.join();
	}
	*/

	//std::thread th1(printnum, 1);
	//std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(1));
	//std::thread th2(printnum, 2);
	//th1.join();
	//th2.join();
	//
   /* int a = 0;*/
	//int b = 0;

	std::thread t1(printnum, 1);
	std::thread t2;
	t2 = t1;
	t2.join();


	return 0;
}
