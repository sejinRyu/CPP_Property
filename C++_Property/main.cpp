#include <iostream>
#include <string>
#include "Property.h"


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
	int b = 2;
	a.A.Set(b);
	std::cout << a.A.Get() << std::endl;
}