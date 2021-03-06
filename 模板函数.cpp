#include <iostream>
#include <vector>

using namespace std;

template <class T> void Swap(T &a, T &b)//模板函数
{
	T temp = a;
	a = b;
	b = temp;
	cout << "使用的模板函数" << endl;
}
void Swap(int &a, int &b)//模板函数
{
	int temp = a;
	a = b;
	b = temp;
	cout << "使用的int交换" << endl;
}

class vec
{
	int value;
	char *p;
public:
	vec(int v){
		p = new char[100];
		value = v;
		cout << "无参构造" << endl;
	}
	vec(const vec &tem)
	{
		p = new char[100];
		value = tem.value;
		cout << "调用了拷贝构造函数" << endl;
	}
	~vec()
	{
		cout << "析构结束" << endl;
		delete p;
	}
	vec& operator=(const vec&tem)//需要重载操作符 Vec_swap函数中的等号是进行浅拷贝 析构会出错
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
	//模板类的隐式推导
	Swap(a, b);
	//模板类的显式推导
	Swap<int>(a, b);
	//模板类的强制模板
	Swap<>(a, b);
	cout << "a=" <<a<<"  b="<<b<< endl;



	//模板函数类中应用
	vec A(100);
	vec B(200);
	Vec_swap(A, B);
	cout << "程序结束" << endl;
	return 0;
}