/**
 * @file	testde.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-05-11
 */

template<typename T, typename U>
auto add(T x, U y) -> decltype(x+y) {
	return x+y;
}

#include <iostream>
#include <array>
#include <vector>
int main()
{
	
	auto tmp = add(1, 2);
	std::cout<<tmp<<std::endl;
	std::array<int, 1024 *1048> arr;
	std::vector<int> vec(1024 *2048);
	std::cout<<sizeof(arr)<<std::endl;
	std::cout<<sizeof(vec)<<std::endl;
	return 0;
}
