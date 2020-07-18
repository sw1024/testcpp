/**
 * @file	test_.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-08
 */

#include <iostream>
#include <ostream>


void testop(int ctl)
{
	std::stringstream os;
	switch(ctl) {
#define XX(ctl)\
	case ctl:\
			 os<<#ctl;\
		break;
		XX(1);
		XX(2);
		XX(3);
	default:
		os<<"default";
		break;
	}
#undef XX
	std::cout<<os.str()<<std::endl;

}

int main()
{
	testop(1);
	testop(2);
	testop(9);

	return 0;
}

