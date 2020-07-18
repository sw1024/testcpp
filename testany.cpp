/**
 * @file	testany.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-05-25
 */

#include <any>
#include <variant>
#include <iostream>

template<class T>
static long long int get_type_id()
{
	static const char addr = 0;
	return reinterpret_cast<long long int>(&addr);
}

int main()
{
	std::any a = "1235";
	std::cout<<a.type().name()<<std::endl;
	//std::cout<<std::any_cast<std::string>(a)<<std::endl;
	//std::cout<<std::any_cast<int>(a)<<std::endl;
	//std::cout<<std::any_cast<double>(a)<<std::endl;
	std::variant<int, float, double, long long, std::string> _var_build;
	_var_build = 100;

	try {
		std::cout<<std::get<int>(_var_build)<<std::endl;
	} catch(const std::bad_variant_access&)
	{
		std::cout<<"parse error"<<std::endl;
	}

	std::cout<<"sizeof any: "<<sizeof(a)<<std::endl;

	std::cout<<"type type id: "<<get_type_id<char>()<<std::endl;
	std::cout<<"type type id: "<<get_type_id<short>()<<std::endl;
	std::cout<<"type type id: "<<get_type_id<int>()<<std::endl;
	std::cout<<"type type id: "<<get_type_id<long>()<<std::endl;
	std::cout<<"type type id: "<<get_type_id<unsigned char>()<<std::endl;
	std::cout<<"type type id: "<<get_type_id<unsigned short>()<<std::endl;
	std::cout<<"type type id: "<<get_type_id<unsigned int>()<<std::endl;
	std::cout<<"type type id: "<<get_type_id<unsigned long>()<<std::endl;
	
	return 0;
}
