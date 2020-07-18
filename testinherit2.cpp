
#include <iostream>

class N
{ 
	public:
		N(long a, long b, long c)
			:m_a(a)
			,m_b(b)
			,m_c(c)
		{
			std::cout<<"call common construct"<<std::endl;
		}

	private:
		long m_a;
		long m_b;
		long m_c;
};

class A : virtual public N
{
	public:
		A()
			:N(11,12,13)
			,a_1(1)
		{
		}

	private:
		long a_1;

};

class B : virtual public N
{
	public:
		B()
			:N(21,22,23)
			,b_1(2)
		{
		}

	private:
		long b_1;

};

class C : public A, public B
{
	public:
		C()
			:N(31,32,33)
			,A()
			,B()
			,c_1(3)
		{
		}



		long c_1;
};

int main()
{
	std::cout<<"N: "<<sizeof(N)<<std::endl;
	std::cout<<"A: "<<sizeof(A)<<std::endl;
	std::cout<<"B: "<<sizeof(B)<<std::endl;
	std::cout<<"C: "<<sizeof(C)<<std::endl;
}
