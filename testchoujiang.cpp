/**
 * @file	testchoujiang.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-05-27
 */


#include <stdlib.h>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

int super = 1;

int randval()
{
	constexpr static int maxval = RAND_MAX / 100;
	auto ret =random() / maxval;
	if (super == 0 && ret == 3)
		return 4;
	return ret;
}

std::mutex mlock;

int lockcount = 0;

void draw(int i)
{
	int count = 0;
	while(true) {
		int give = randval();
		if (give == 3) {
			if (super != 0 ) {
				std::lock_guard<std::mutex> tlock(mlock);
				lockcount ++;
				if (super != 0) {
					super = 0;
				} else {
					give = randval();
				}
			} else {
				give = randval();
			}
		}

		if (++count > 1000) {
			break;
		}
	}


}


int main()
{
	std::vector<std::thread> tvec(10);
	for (int i = 0; i <10; i++) {
		tvec[i] = std::thread(draw, i);
	}

	for (auto& it : tvec) {
		it.join();
	}

	std::cout<<"lockcount: "<<lockcount<<std::endl;

	return 0;
}
