#include <iostream>
#include <vector>

using namespace std;

template <class T> class X_stack{
	vector<T> arr;
public:
	void push(T &&obj)
	{
		arr.push_back(obj);
	}
	void pop()
	{
		arr.pop_back();
	}
	T& top()
	{
		return arr.back();
	}
};
void Xprint()
{
	cout << endl;
}
//�ݹ���
template <class first, class...arg> void Xprint(first f,arg...d){
	cout << f << endl;
	Xprint(d...);
}

int main()
{
	X_stack<int> arr;
	arr.push(5);
	arr.pop();
	arr.push(4);
	arr.top();
	Xprint(2,3,4,"56669");
	cout << "�������" << endl;
	return 0;
}