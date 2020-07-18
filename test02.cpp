/**
 * @file test02.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-08-15
 */

#include <iostream>

//1. 可变模板参数函数
template<class... T>
void f(T... args)
{
	std::cout<<sizeof...(args) << std::endl;
}

//2 双层模板 递归方式展开参数包
void print()
{
	std::cout<<"empty"<<std::endl;
}

template<class T, class ... Args>
void print(T head, Args...reset)
{
	std::cout<<"parameter:"<<head<<std::endl;
	print(reset...); //剩余的所有参数 省略号在右边
}

template<typename T>
T sum(T t)
{
	return t;
}


template<typename T, class ... Types>
T sum(T first, Types ... reset)
{
	return first +sum<T>(reset...); //出入整个剩余参数
}

//3. 逗号表达式揭开参数包


int main()
{
	f(1);
	f(1, "hello", 2);
	f(1, 11, NULL);

	print(1,"hello",3,"world");
	std::cout<<sum(1,2,3,4)<<std::endl;

	return 0;
}
