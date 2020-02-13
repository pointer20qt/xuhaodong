#include <iostream>

//多态 虚析构 防止内存泄漏
class A
{
public:
	void run()
	{
		std::cout << "调用了A的run函数" << std::endl;
	}
	virtual ~A()
	{
		std::cout << "调用了A的析构" << std::endl;
	};
};
class B :public A
{
public:
	void run()
	{
		std::cout << "调用了B的run函数" << std::endl;
	}
	virtual ~B()
	{
		std::cout << "调用了B的析构" << std::endl;
	};
};
int main()
{
	A *a = new B();//基类指针指向子类对象
	a->run();
	delete a;//构造先构造基类 虚构先虚构子类
	return 0;
}