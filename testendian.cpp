/**
 * @file	testendian.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-06-12
 */

#include <stdint.h>
#include <byteswap.h>
#include <iostream>
constexpr int BYTE_ORDER1 = (char)1 >>1;
int main()
{
	
	std::cout<<BYTE_ORDER<<std::endl;
	std::cout<<BIG_ENDIAN<<std::endl;
	std::cout<<LITTLE_ENDIAN<<std::endl;

	int a = 0x12345678;
	char b = *reinterpret_cast<char*>(&a);
	if (b == 0x78) {
		std::cout<<"this is little endian"<<std::endl;
		return 0;
	}
	std::cout<<"this is big endian"<<std::endl;

	return 0;
}
