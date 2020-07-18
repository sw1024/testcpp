/**
 * @file	testinherit3.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-06-01
 */

#include <iostream>

class A{
	public:
		A() {};
		virtual ~A() {};

		virtual int printa() {return a; }

	private:
		int a = 10;
};

class B{
	public:
		B() {};
		virtual ~B() {};

		virtual int printa() {return a; }

	private:
		int a = 10;
};

class C : public A, B
{
	public:
		C() {};
		virtual ~C() {}

		int aa() { return 1;}


};

int main()
{
	C c;
	//c.printa();
	std::cout<<c.aa()<<std::endl;

	return 0;
}
