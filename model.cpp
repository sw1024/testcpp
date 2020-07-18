/**
 * @file	model.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-05-01
 */


#include <iostream>

template<int N>
class Fib
{
	public:
	static constexpr int Value = Fib<N-1>::Value + Fib<N-2>::Value;
};

template<>
class Fib<1>
{
	public:
	static constexpr int Value = 1;
};

template<>
class Fib<2>
{
	public:
	static constexpr int Value = 2;
};

constexpr auto fact(int n)
{
	if(n == 1)
		return 1;

	return n * fact(n - 1);
}

int main(int argc, char* argv[])
{
	std::cout<<Fib<5>::Value<<std::endl;

	//constexpr auto val = fact(argc);
	//std::cout<<val<<std::endl;


	return 0;
}
