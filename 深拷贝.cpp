#include <iostream>

class school{
	friend void start();
	friend class hospital;
	std::string schoolName;
public:
	school(){
		std::cout << "无参构造了" << std::endl;
	}
	school(const school &p):schoolName(p.schoolName){
		std::cout << "拷贝构造了" << std::endl;
	}
	~school()
	{
		std::cout << "析构了" << std::endl;
	}
};

