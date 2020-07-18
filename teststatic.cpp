/**
 * @file	teststatic.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-25
 */

#include <iostream>
#include <unordered_map>
#include <stdlib.h>

class TStatic
{
	public:
		TStatic()
		{
			a = rand();
			b = rand();
			c = rand();
			std::cout<<"random data"<<RAND_MAX<<std::endl;

		}

		int c = 0;
		static int a;
	private:
		static int b;

};

static TStatic tt;
int TStatic::a = 1;
int TStatic::b = 2;


int main()
{
	std::cout<<TStatic::a<<std::endl;
	std::cout<<tt.a<<std::endl;

	std::unordered_map<int, int> aa(5);
	aa.insert(std::make_pair(1,2));
	aa.insert(std::make_pair(2,2));
	aa.insert(std::make_pair(3,2));
	aa.insert(std::make_pair(4,2));
	aa.insert(std::make_pair(5,2));
	aa.insert(std::make_pair(6,2));
	aa.insert(std::make_pair(7,2));

	for (auto& it : aa) {
		std::cout<<"hashmap:"<<it.first<<"-"<<it.second<<std::endl;
	}

	TStatic* tn = nullptr;
	std::cout<<tn->c<<std::endl;
	

	return 1;
}
