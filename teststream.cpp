/**
 * @file	teststream.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-14
 */

#include <fstream>
#include <iostream>

int main()
{
	std::ofstream ms;
	ms.open("stream.txt", std::ios::app);
	ms<<"hello world"<<std::endl;
	ms.close();
	return 0;
}
