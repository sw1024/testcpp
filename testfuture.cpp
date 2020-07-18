/**
 * @file testfuture.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-08-16
 */

#include <condition_variable>
#include <mutex>
#include <chrono>
#include <iostream>
#include <future>
#include <thread>
#include <queue>

int main()
{
	/*
	std::packaged_task<int()> task([]() { return 7; });
	std::future<int> result = task.get_future();
	std::thread(std::move(task)).detach();
	result.wait();
	std::cout<<"Done"<<std::endl;
	std::cout<<"Result is "<<result.get()<<std::endl;
	*/

	std::queue<int> produced_nums;
	std::mutex m;
	std::condition_variable cond_var;

	bool done = false;
	bool notifyed = false;

	//生产数据
	std::thread producer([&]() {
			for (int i = 0; i <5; i++) {
				std::this_thread::sleep_for(std::chrono::seconds(1));

				//创建互斥锁
				std::unique_lock<std::mutex> lock(m);
				std::cout<<"producing "<<i<<"\n";
				produced_nums.push(i);
				notifyed = true;
				cond_var.notify_one();
			}
			done = true;
			cond_var.notify_all();
		});

	//消费者线程
	std::thread consumer([&]() {
			std::unique_lock<std::mutex> lock(m);
			while(!done) {
				while(!notifyed) {
					cond_var.wait(lock);
				}

				while(!produced_nums.empty()) {
					std::cout<<"comsuming "<<produced_nums.front()<<'\n';
					produced_nums.pop();
				}
				notifyed = false;
			}
		});

	producer.join();
	consumer.join();
	return 0;
}





