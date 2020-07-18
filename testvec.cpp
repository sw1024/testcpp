/**
 * @file	testvec.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-25
 */

#include <vector>
#include <iostream>

int main()
{
	std::vector<int> aa(10);
	std::cout<<sizeof(aa)<<std::endl;
	std::cout<<aa.capacity()<<std::endl;
	std::cout<<aa.size()<<std::endl;
	aa[2] = 5;
	auto& tt = aa[2];
	aa.insert(aa.begin(), 100);
	std::cout<<tt<<std::endl;;
	for (auto& it : aa) {
		std::cout<<"aa: "<<it<<std::endl;
	}

	return 0;
}
