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
	int& operator [](unsigned int i){//�˴�����ֵ ���������� ���򽫱�ɲ����޸ĵ���ֵ
		return srt[i];
	}
	int getx()
	{
		return x;
	}
};

int main()
{
	vec A({1,2});//��������ͬ����ֵͳһ��ֵ
	cout << A[1] << endl;
	return 0;
}