#include <iostream>
#include <string>
using namespace std;

class school{
	
public:
	string schoolName;
	friend void start(school &p);
	school():schoolName("大学"){

	}
	~school(){

	}
};

void start(school &p)
{
	p.schoolName = "一中";
	cout<< p.schoolName << endl;
	std:; cout << "运行了"__FUNCTION__ << std::endl;
}
int main()
{
	school s;
	start(s);
	return 0;
}
