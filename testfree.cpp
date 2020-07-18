/**
 * @file	testfree.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-05-10
 */

#include <iostream>
#include <vector>

struct Heap
{
	int a =0;
	int b =0;
};

const int c = 100;


void testdeep(int idx)
{
	int idxx = idx + 1;
	//std::cout<<idx<<std::endl;
	testdeep(idxx);
}

int main()
{
	static int tmp = 100;
	tmp += 1;
	int a = 1;
	auto b = new Heap();

	b->a = a;
//	testdeep(1);
	//std::vector<long> aa(1000000, 10);
	//std::cout<<aa[10]<<std::endl;
	int aa[2048][1024] = {};

	std::cout<<aa[1][1]<<std::endl;
	
	return 0;
}
