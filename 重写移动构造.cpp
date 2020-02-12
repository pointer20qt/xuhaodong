#include<iostream>
#include<vector>
using namespace std;

class A_2
{
public:
	A_2() :m_ptr(new int(0))
	{
		std::cout << "construct" << std::endl;
	}

	A_2(const A_2& a) :m_ptr(new int(*a.m_ptr)) //Éî¿½±´
	{
		std::cout << "copy construct" << std::endl;
	}

	A_2(A_2&& a) :m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
		std::cout << "move construct:" << std::endl;
	}

	~A_2()
	{
		std::cout << "destruct" << std::endl;
		delete m_ptr;
	}

private:
	int* m_ptr;
};

A_2 Get(bool flag)
{
	A_2 a;
	A_2 b;
	if (flag)
		return a;
	else
		return b;
}

int right_value_ref2()
{
	A_2 a = Get(false);

	return 0;
}
