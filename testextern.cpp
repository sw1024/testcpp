/**
 * @file testextern.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-09-01
 */

#include <iostream>

int sumFunc(int, int);

int main()
{
	extern int sum;
	sum = sumFunc(1, 2);
	std::cout<<"sum:"<<sum<<std::endl;

	return 0;
}


int sum = 0;

int sumFunc(int a, int b)
{
	return a+ b;
}
