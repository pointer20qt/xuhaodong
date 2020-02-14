#include <iostream>
#include <vector>

using namespace std;

class vec
{
	int x;
	vector<int> res;
	int* srt;
public:
	vec() = default;
	vec(const initializer_list<int> v) :x(*v.begin()), res(*v.begin() + 1)
	{
		srt= new int[v.size()];
		int j = 0;
		for (auto i = v.begin(); i != v.end(); i++)
		{
			srt[j++] = *i;
		}
	}
	int& operator [](unsigned int i){//此处返回值 必须用引用 否则将变成不可修改的左值
		return srt[i];
	}
	int getx()
	{
		return x;
	}
};

int main()
{
	vec A({1,2});//给对象中同类型值统一赋值
	cout << A[1] << endl;
	return 0;
}