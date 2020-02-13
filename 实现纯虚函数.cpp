#include <iostream>

//基类 当有纯虚函数时 类变为基类 只能被继承 子类需要实现虚函数
class A
{
public:
	virtual void run() = 0;
};
class B :public A
{
public:
	void run(){
		std::cout << "在B中实现纯虚函数" << std::endl;
	}
};
int main()
{
	B b;
	b.run();
	return 0;
}