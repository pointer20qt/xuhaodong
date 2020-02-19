//怎么通过rand生成[0,a)的数 rand()%a;
//怎么通过rand生成[a,b)的数 rand()%(b-a)+a;
//怎么生成一个0~1的随机小数((double) rand())/RAND_MAX;
//怎么生成a~b的随机小数
//传入0到100的整数，概率性判断成功,成功返回true
//传入0到1的double，概率性判断成功，成功返回ture。

#include <iostream>

using namespace std;

bool probability(int n){
	//(0-RAND_Max);
	int p = ((double) rand())% RAND_MAX;
	if (p >=n){
		return false;
		cout << "中奖" << endl;
	}
	else{
		return true;
		cout << "未中奖" << endl;
	}
}

int main(){
	//初始化随机种子 time(0)为1970年到现在的秒数
	srand(time(0));
	//取出一个随机数 rand();

	return 0;
}