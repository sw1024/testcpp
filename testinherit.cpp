/**
 * @file testinherit.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-09-30
 */
#include <iostream>


class TestA
{
	public:
		int pub = 3;
		void print() {
			std::cout<<"hello world"<<std::endl;
		}

	protected:
		int pro = 2;
	private:
		int pri = 1;
};

class TestB : public TestA
{
	public:
		void print() {
			//std::cout<<pri<<std::endl;
			std::cout<<pro<<std::endl;
			std::cout<<pub<<std::endl;

		}
};

int main()
{
	TestB b;
	b.print();

	TestA* a = new TestB();
	a->print();
	//((TestB*)a)->print();

	return 0;
}


