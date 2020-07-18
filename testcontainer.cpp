/**
 * @file	testcontainer.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-06-03
 */

#include <iostream>
#include <vector>

struct Data
{
	Data(int i)
		:val(i)
	{}

	int val = 0;

};

void test_vector()
{
	std::vector<Data> vec(10, Data{1});
	Data data(10);
	//vec.reserve(20); //改变capacity
	vec.resize(15, data);// 改变size
	vec.emplace_back(9);
	std::cout<<"size: "<<vec.size()<<std::endl;;
	std::cout<<"capacity: "<<vec.capacity()<<std::endl;;

	for (auto& it : vec) {
		std::cout<<it.val<<std::endl;;
	}

	std::vector<int> ivec(10, 1);
	ivec.resize(20, 2);
	std::cout<<"i-size: "<<ivec.size()<<std::endl;;
	std::cout<<"i-capacity: "<<ivec.capacity()<<std::endl;;
	for (auto& it : ivec) {
		std::cout<<it<<std::endl;;
	}
}

int main()
{
	test_vector();



	return 0;
}
