//��ôͨ��rand����[0,a)���� rand()%a;
//��ôͨ��rand����[a,b)���� rand()%(b-a)+a;
//��ô����һ��0~1�����С��((double) rand())/RAND_MAX;
//��ô����a~b�����С��
//����0��100���������������жϳɹ�,�ɹ�����true
//����0��1��double���������жϳɹ����ɹ�����ture��

#include <iostream>

using namespace std;

bool probability(int n){
	//(0-RAND_Max);
	int p = ((double) rand())% RAND_MAX;
	if (p >=n){
		return false;
		cout << "�н�" << endl;
	}
	else{
		return true;
		cout << "δ�н�" << endl;
	}
}

int main(){
	//��ʼ��������� time(0)Ϊ1970�굽���ڵ�����
	srand(time(0));
	//ȡ��һ������� rand();

	return 0;
}