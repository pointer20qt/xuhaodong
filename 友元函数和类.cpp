#include <iostream>
#include <string>
using namespace std;

class school{
	
public:
	string schoolName;
	friend void start(school &p);
	school():schoolName("��ѧ"){

	}
	~school(){

	}
};

void start(school &p)
{
	p.schoolName = "һ��";
	cout<< p.schoolName << endl;
	std:; cout << "������"__FUNCTION__ << std::endl;
}
int main()
{
	school s;
	start(s);
	return 0;
}
