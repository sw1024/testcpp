/**
 * @file	producter.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-06-24
 */

#include <queue>
#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

int main()
{
	std::queue<int> produced_nums;
	std::mutex mtx;
	std::condition_variable cv;
	bool notified = false;

	auto producter = [&]() {
		for (int i = 0; ; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(900));
			std::unique_lock<std::mutex> lock(mtx);
			std::cout<<"producting: "<<i<<std::endl;
			produced_nums.push(i);
			notified = true;
			cv.notify_all();
		}
	};

	auto consumer = [&]() {
		while(true) {
			std::unique_lock<std::mutex> lock(mtx);
			while(!notified) {
				cv.wait(lock);
			}
   /*         lock.unlock();*/
			//std::this_thread::sleep_for(std::chrono::milliseconds(900));
			//lock.lock();
			while(!produced_nums.empty()) {
				std::cout<<"consumer: "<<produced_nums.front()<<std::endl;
				produced_nums.pop();
			}
			notified = false;
		}


	};

	std::thread p(producter);

	std::thread cs[2];
	for (int i = 0; i <2; i ++) {
		cs[i] =  std::thread(consumer);
	}
	p.join();
	for (auto& it : cs)
		it.join();

	return 0;

}
