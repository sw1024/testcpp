/**
 * @file	testlazy.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-03-13
 */

#include <functional>
#include <iostream>

template<typename T>
struct Lazy
{
	//Lazy() {}

	template<typename Func, typename ... Args>
	Lazy(Func& f, Args && ... args)
	{
		m_func = [&f, &args...]{return f(args);}
	}

	T& Value()
	{
		return m_func();
	}
	private:
	std::function<T()> m_func;
};
