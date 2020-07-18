/**
 * @file	testfold.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-27
 */

#include <iostream>

template <class T>
void print(T&& val)
{
	std::cout<<val<<std::endl;
}

template <class... Args>
void TestPrint(Args&&... args)
{
	auto val = (args - ... - 1);
	std::cout<<val<<std::endl;

	//(...,print(args));
	//std::cout<<(args<<...)<<std::endl;

}

int main()
{
	TestPrint<int>(1,2,3,4);
	//TestPrint<int>(1,2,3,"hello");
	return 0;
}
