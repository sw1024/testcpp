/**
 * @file	oob.h
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-07-23
 */
#pragma once

class Register
{
	public:
		void Register()
		{
			std::cout<<"register idx: "<<idx++<<std::endl;
		}
	private:
		static int idx = 0;

};

class Object
{
	public:
		static Register register_;
};




