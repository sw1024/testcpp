/**
 * @file test01.cpp
 * $Id$
 * @brief	
 * @author My name SunWu
 * @date 2019-07-14
 */

#include <iostream>
#include <sstream>
#include <variant>
#include <list>
#include <string>
#include <algorithm>
#include <utility>
#include <string>
#include <math.h>

class cat {
	public:
		cat(std::string n)
			:name(n)
		{}

		void meow() const {
			std::cout<<name<<":meow"<<std::endl;
		}
			
	private:
		std::string name;

};

class dog{
	public:
		dog(std::string n)
			:name(n)
		{}

		void woof() const {
			std::cout<<name<<":woof"<<std::endl;
		}
			
	private:
		std::string name;

};

using animal = std::variant<dog, cat>;

template<typename T>
bool is_type(const animal& a){
	return std::holds_alternative<T>(a);
}

struct animal_voice {
	void operator() (const dog& d) const { d.woof();  }
	void operator() (const cat& c) const { c.meow();  }
};

template<typename ... Ts>
void print(Ts ... ts)
{
	int i = 0;
	(..., (std::cout<<ts<<":"<<i++<<std::endl));
}

template<typename ... Ts>
auto sum(Ts ... ts)
{
	return (ts + ...);
}

int main()
{

	std::list<animal> l { cat("Tuba"), dog("pite"), cat("qiuqiu") };

	for (const auto& it : l) {
		switch(it.index()) {
			case 0:
				{
					std::get<dog>(it).woof();
				}
				break;
			case 1:
				{
					std::get<cat>(it).meow();
				}
				break;
			default:
				{
				}
		}
	}
/*
	std::variant<int, float> v;
	v = 12;
	int i = std::get<int>(v);
	std::cout<<"int:"<<i<<std::endl;
	float f = std::get<float>(v);
	std::cout<<"float:"<<f<<std::endl;
	*/
	int the_sum {sum(1,2,3,4,5)};
	std::cout<<sum(12,2,3,4)<<std::endl;
	std::cout<<the_sum<<std::endl;

	std::string a {"hello "};
	std::string b {"world"};
	std::cout<<sum(a, b)<<std::endl;

	print(1,2,3);

	std::pair<int, std::string> mypair(1, "Ivy");
	std::pair mypair2(2, "Ivy");
	//mypair.first = 1;
	//mypair.second= "Asce";

	const auto& [age, name] = mypair;
	std::cout<<name<<":"<<age<<std::endl;

	std::cout<<mypair.first<<":"<<mypair.second<<std::endl;

	int x2  {5};
	std::cout<<x2<<std::endl;
	std::cout<<mypair2.first<<":"<<mypair2.second<<std::endl;

	std::stringstream ss;
	ss<<"hello world";
	std::string out, out1;
	ss>>out;
	ss>>out1;
	std::cout<<out<<std::endl;
	std::cout<<out1<<std::endl;

	char buf[128] = {'1', '2', '\0', '3', '4'};

	std::string tmp(buf, 128);
	std::cout<<tmp.c_str()<<std::endl;
	std::cout<<tmp.length()<<std::endl;
	std::cout<<tmp.size()<<std::endl;

	std::string tmp2 = tmp;
	std::cout<<tmp2.length()<<std::endl;
	std::cout<<tmp2.size()<<std::endl;
	std::cout<<tmp2<<std::endl;

	std::string tmp3 = buf;
	std::cout<<tmp3.length()<<std::endl;
	std::cout<<tmp3.size()<<std::endl;
	std::cout<<tmp3<<std::endl;

	

	long t = pow(2,24);
	std::cout<<t<<std::endl;
	std::cout<<1024 * 64<<std::endl;
	return 0;
}


