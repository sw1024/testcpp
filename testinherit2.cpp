
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

		static bool IsTrue() { return true;};
		virtual void print() { std::cout<<"N"<<std::endl;}

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

		static bool IsTrue() { return true;};
		virtual void print() { std::cout<<"A"<<std::endl;}
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

		//static bool IsTrue() { return false;}
		virtual void print() { std::cout<<"B"<<std::endl;}

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

		virtual void print() { std::cout<<"C"<<std::endl;}



		long c_1;
};

int main()
{
	std::cout<<"N: "<<sizeof(N)<<std::endl;
	std::cout<<"A: "<<sizeof(A)<<std::endl;
	std::cout<<"B: "<<sizeof(B)<<std::endl;
	std::cout<<"C: "<<sizeof(C)<<std::endl;

	N* o = (N*)new A();

	std::cout<<N::IsTrue()<<std::endl;
	std::cout<<A::IsTrue()<<std::endl;
	std::cout<<B::IsTrue()<<std::endl;
	std::cout<<o->IsTrue()<<std::endl;

	o->print();
}
