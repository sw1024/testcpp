/**
 * @file	function.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-07-01
 */

#include <iostream>

int hello(long val)
{
	std::cout<<val<<std::endl;
	return 0;
}

typedef int (*cfunction)(long v);

int main()
{
	cfunction a = &hello;
	auto b = (*a)(4);
	std::cout<<b<<std::endl;;

	return 0;
}
