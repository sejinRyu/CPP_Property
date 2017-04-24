#include <iostream>
#include <string>
#include "Property.h"


class Test
{
	std::string a;
	const std::string Get() const
	{
		return a;
	}
	void Copy(const std::string& a)
	{
		std::cout << "copy" << std::endl;
		this->a = a;
	}
	void Move(std::string&& a)
	{
		std::cout << "move" << std::endl;
		std::swap(this->a, a);
	}
public:
	Property<std::string, Test> A;
	Test() :A(*this, &Test::Get, &Test::Copy, &Test::Move) {}
};

class Test1
{
	int a;
	const int Get() const
	{
		return a;
	}
	void Set(const int& a)
	{
		std::cout << "set" << std::endl;
		this->a = a;
	}
public:
	Property<int, Test1> A;
	Test1() :A(*this, &Test1::Get, &Test1::Set) {}
};

int main()
{
	Test a;
	a.A.Set("abd");
	std::cout << a.A.Get() << std::endl;
}