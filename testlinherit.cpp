/**
 * @file	testlinherit.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-05-06
 */

#include <iostream>

class N
{ 
	public:
		N(int a, int b, int c)
			:m_a(a)
			,m_b(b)
			,m_c(c)
		{
		}

	private:
		int m_a;
		int m_b;
		int m_c;
};

class A : virtual public N
{
	public:
		A(int a1)
			:N(11,12,13)
			,a_1(a1)
		{
		}

	private:
		int a_1;

};

class B : public N
{
	public:
		B(int a1)
			:N(21,22,23)
			,b_1(a1)
		{
		}

	private:
		int b_1;

};

class C : public A, public B
{
	public:
		C(int a1)
			:N(31,32,33)
			,A(1)
			,B(2)
			,c_1(a1)
		{
		}


	private:
		int c_1;
};

int main()
{
	std::cout<<"N: "<<sizeof(N)<<std::endl;
	std::cout<<"A: "<<sizeof(A)<<std::endl;
	std::cout<<"B: "<<sizeof(B)<<std::endl;
	std::cout<<"C: "<<sizeof(C)<<std::endl;
}
