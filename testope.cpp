
#include <iostream>
#include <functional>


class Test
{
	public:
		//前置++
		Test& operator ++() {
			a++;
			std::cout<<"pre ++ operator"<<std::endl;
			return *this;
		}

		Test& operator --() {
			--a;
			std::cout<<"pre -- operator"<<std::endl;
			return *this;
		}

		//后置++
		Test& operator ++(int) {
			++a;
			std::cout<<"aft ++ operator"<<std::endl;
			return *this;
		}

		Test& operator --(int) {
			--a;
			std::cout<<"aft ++ operator"<<std::endl;
			return *this;
		}

		operator int&&()
		{
			std::cout<<"operator &&"<<std::endl;
			return std::move(a);
		}

		operator int& ()
		{
			std::cout<<"operator &"<<std::endl;
			return a;
		}

		operator int ()
		{
			std::cout<<"operator val"<<std::endl;
			return a;
		}

	private:
		int a = 0;
};



void myprint(Test a)
{
	std::cout<<"hello this is value"<<std::endl;
};

void myprint(Test& a)
{
	std::cout<<"hello this is & value"<<std::endl;
};

void myprint(Test&& a)
{
	std::cout<<"hello this is && value"<<std::endl;
};

int main()
{
	Test c;
	//int cv = c;
	//std::cout<<cv<<std::endl;
	//auto e = std::move(c);
	//int cv = (int&)c;
	//myprint((Test&)c);
	myprint(std::cref(c));


	return 0;
}
