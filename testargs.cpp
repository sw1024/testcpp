/**
 * @file	testargs.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-05-19
 */

#include <iostream>

template<typename ... Args>
void Print(Args ... args)
{
	//测试有折叠
	auto val = (args - ... - 5);
	std::cout<<val<<std::endl;

	(std::cout<<...<<args)<<" "<<std::endl;;//<<std::endl;
	std::cout<<std::endl;
}

int main()
{
	Print(2,1);

	return 0;
}
