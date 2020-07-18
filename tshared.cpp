/**
 * @file tshared.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-09-07
 */


#include <iostream>
#include <memory>

class TestShared
{
	public:
		TestShared(int num) 
			:_val(num)
		{
			std::cout<<"TestShared construct: "<<_val<<std::endl;
		}
		~TestShared() {
			std::cout<<"TestShared deconstruct: "<<_val<<std::endl;
		}
		operator int& () {
			return _val;
		}
	private:
		int _val;
};

using intPtr = std::shared_ptr<TestShared>;
int main()
{
	void* a2 = nullptr;

	std::weak_ptr<TestShared> wptr;

	{
	intPtr a1 = std::make_shared<TestShared>(12);
	//std::cout<<*a1<<std::endl;
	a2 = (void*)a1.get();
	std::cout<<a1.use_count()<<std::endl;
	wptr = a1;
	}
	std::cout<<*(int*)a2<<std::endl;

	intPtr a3(new TestShared(11));
	std::cout<<(int)(*a3)<<std::endl;

	intPtr a4 = a3;
	std::cout<<a3.use_count()<<std::endl;
	std::cout<<a4.use_count()<<std::endl;
	std::cout<<a4.unique()<<std::endl;

	auto uptr = std::make_unique<TestShared>(10);

	auto uptr2 = std::move(uptr);
	std::cout<<"uptr: "<<uptr.get()<<std::endl;
	std::cout<<"uptr: "<<(int)*uptr2<<std::endl;

	if (!wptr.expired()) {
		std::cout<<"uptr still can use:"<<(int)(*wptr.lock())<<std::endl;
	} else {
		std::cout<<"uptr still can not use"<<std::endl;
	}
}
