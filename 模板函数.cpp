#include <iostream>
#include <vector>

using namespace std;

template <class T> void Swap(T &a, T &b)//ģ�庯��
{
	T temp = a;
	a = b;
	b = temp;
	cout << "ʹ�õ�ģ�庯��" << endl;
}
void Swap(int &a, int &b)//ģ�庯��
{
	int temp = a;
	a = b;
	b = temp;
	cout << "ʹ�õ�int����" << endl;
}

class vec
{
	int value;
	char *p;
public:
	vec(int v){
		p = new char[100];
		value = v;
		cout << "�޲ι���" << endl;
	}
	vec(const vec &tem)
	{
		p = new char[100];
		value = tem.value;
		cout << "�����˿������캯��" << endl;
	}
	~vec()
	{
		cout << "��������" << endl;
		delete p;
	}
	vec& operator=(const vec&tem)
	{
		delete p;
		p = new char[100];
		value = tem.value;
		return *this;
	}
};
void Vec_swap(vec &a, vec &b)
{
	vec temp(a);
	a = b;
	b = temp;
}

int main()
{
	int a(20);
	int b(10);
	//ģ�������ʽ�Ƶ�
	Swap(a, b);
	//ģ�������ʽ�Ƶ�
	Swap<int>(a, b);
	//ģ�����ǿ��ģ��
	Swap<>(a, b);
	cout << "a=" <<a<<"  b="<<b<< endl;



	//ģ�庯������Ӧ��
	vec A(100);
	vec B(200);
	Vec_swap(A, B);
	cout << "�������" << endl;
	return 0;
}