/**
 * @file testyou.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-08-15
 */

#include <iostream>
#include <string>
#include <vector>

class Test
{
	public:
	int a= 0;
};



int main()
{
	std::string lv1 = "hello world";
	std::string&& lv2 = std::move(lv1);
	lv1 = "asdrf";
	std::cout<<lv1<<std::endl;
	std::cout<<lv2<<std::endl;
	const std::string& lv3 = lv1 + lv1;
	lv1 = "this is a  ";
	std::cout<<lv3<<std::endl;
	std::cout<<lv1<<std::endl;

	/*
	std::vector<std::string> strvec;
	strvec.push_back(std::move(lv1));
	std::cout<<lv1<<std::endl;
	std::cout<<strvec[0]<<std::endl;
	*/
	std::string lvn = std::move(lv1);
	std::cout<<"lvn:"<<lvn<<std::endl;
	std::cout<<lv1<<std::endl;

	std::string&& lvm = "hello game";
	{
		lvm = "hello game 2";
	}
	std::cout<<lvm<<std::endl;
	auto& lvm2 = lvm;
	lvm = "this";
	std::cout<<lvm<<std::endl;
	std::cout<<lvm2<<std::endl;

	Test a;
	a.a = 3;

	auto&& c= std::move(a);
	std::cout<<c.a<<std::endl;
	std::cout<<a.a<<std::endl;

	return 0;
}
