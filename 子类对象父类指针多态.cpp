#include <iostream>

//��̬ ������ ��ֹ�ڴ�й©
class A
{
public:
	void run()
	{
		std::cout << "������A��run����" << std::endl;
	}
	virtual ~A()
	{
		std::cout << "������A������" << std::endl;
	};
};
class B :public A
{
public:
	void run()
	{
		std::cout << "������B��run����" << std::endl;
	}
	virtual ~B()
	{
		std::cout << "������B������" << std::endl;
	};
};
int main()
{
	A *a = new B();//����ָ��ָ���������
	a->run();
	delete a;//�����ȹ������ �鹹���鹹����
	return 0;
}