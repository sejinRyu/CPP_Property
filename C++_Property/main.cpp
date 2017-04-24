#include <iostream>
#include <string>
#include "Property.h"
//#define Property(Get,Set) __declspec(property(get=Get,put=Set)) 
//class test
//{
//	int a;
//	int b;
//
//public:
//	int getA() { std::cout << "getA" << std::endl; return a;  }
//	void setA(int a) { std::cout << "setA" << std::endl; this->a = a;}
//	int getB() { std::cout << "getB" << std::endl; return b; }
//	void setB(int b) { std::cout << "setB" << std::endl; this->b = b; }
//	Property(getA, setA) int A;
//	Property(getB, setB) int B;
//	/*__declspec(property(get = getA, put = setA)) int A;
//	_declspec(property(get = getB, put = setB)) int B;*/
//};


class Test
{
	int a;
	const int Get() const
	{
		return a;
	}
	void Copy(const int& a)
	{
		std::cout << "copy" << std::endl;
		this->a = a;
	}
	void Move(int&& a)
	{
		std::cout << "move" << std::endl;
		std::swap(this->a, a);
	}
public:
	Property<int, Test> A;
	Test() :A(*this, &Test::Get, &Test::Copy, &Test::Move) {}
};

int main()
{
	Test a;
	a.A = 3;
	std::cout << a.A.Get() << std::endl;
}