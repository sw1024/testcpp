/**
 * @file	testassert.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-06-15
 */

#include <iostream>
#include <cassert>

int main()
{
	assert(true);
	std::cout<<"test assert "<<std::endl;
	assert(false);

	return 0;
}
