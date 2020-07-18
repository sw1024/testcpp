/**
 * @file testexplicit.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-09-01
 */

#include <iostream>

class A
{

};

class B
{
	public:
		explicit B(const A& x)  {
			std::cout<<"B'a constructor"<<std::endl;
		}

		B& operator = (const A& a) {
			std::cout<<"B'a assignment"<<std::endl;
			return *this;
		}

		explicit operator A() {
			std::cout<<"B's conversion"<<std::endl;
			return A();
		}
};

void fn(B arg)
{

	std::cout<<"function"<<std::endl;
}

int main()
{
	A foo;
	B bar(foo);
	//B bar1 = foo;
	bar = foo;
	fn(bar);

	return 0;
}

