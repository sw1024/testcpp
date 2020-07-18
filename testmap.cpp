/**
 * @file	testmap.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-26
 */

#include <map>
#include <iostream>
#include <functional>


struct Compare
{
	bool operator() (const int a, const int b) const
	{
		if (a > b)
			return true;

		if (a < b)
			return false;

		return true;
	}


};


int main()
{
	std::map<int, int, Compare> tmpmap;
	tmpmap.insert(std::make_pair(1,2));
	tmpmap.insert(std::make_pair(2,2));
	tmpmap.insert(std::make_pair(3,2));
	tmpmap.insert(std::make_pair(4,2));
	tmpmap.insert(std::make_pair(5,2));
	for (auto& it : tmpmap) {
		std::cout<<it.first<<":"<<it.second<<std::endl;
	}

	std::cout<<sizeof(tmpmap)<<std::endl;
	std::cout<<sizeof(std::pair<int,int>)<<std::endl;

	std::cout<<sizeof(std::function<bool(int,int)>)<<std::endl;


	return 0;
}
