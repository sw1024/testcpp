/**
 * @file	testpromise.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-07-01
 */

#include <iostream>
#include <thread>
#include <string>
#include <future>
#include <chrono>

void read(std::future<std::string>* future)
{
	std::cout<<future->get()<<std::endl;
	//std::cout<<future->get()<<std::endl;
}

void read1(std::future<int> future)
{
	try{
		future.get();
	} catch (std::future_error& e) {
		std::cerr<<e.code()<<std::endl<<e.what()<<std::endl;
	}
}

int main()
{
	/*
	std::promise<std::string> promise;
	auto future = promise.get_future();
	std::thread thread(read, &future);
	*/
	std::thread thread;
	{
	std::promise<int> promise;
	thread = std::thread(read1, promise.get_future());
	}

	//std::this_thread::sleep_for(std::chrono::seconds(1));

	//promise.set_value("hello world");
	//promise.set_value("hello world");
	thread.join();

	return 0;

}
