#include <iostream>

//���� ���д��麯��ʱ ���Ϊ���� ֻ�ܱ��̳� ������Ҫʵ���麯��
class A
{
public:
	virtual void run() = 0;
};
class B :public A
{
public:
	void run(){
		std::cout << "��B��ʵ�ִ��麯��" << std::endl;
	}
};
int main()
{
	B b;
	b.run();
	return 0;
}