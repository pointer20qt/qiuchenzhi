#include<iostream>
#include<time.h>
#include"tool.h"
using namespace std;//��ô����a~b�����С��//����0��100���������������жϳɹ�,�ɹ�����true//����0��1��double���������жϳɹ����ɹ�����turerand()�������������ȡ��һ��    srand(time(0)) ��ʼ�����������
bool rrand(double a){
	//rand()ȡֵ��0~RAND_MAX��
	double p = ((double)rand()) / RAND_MAX;
	if (p < a){
		return true;
	}
	return false;
}
int main(){
	srand(time(0));
	
	int a = 10;
	int b = 20;
	////����[0, a)����
	rand() % a;
	////����[a,b)����	
	rand() % (b - a) + a;
	//����һ��0~1�����С��double
	((double)rand()) / RAND_MAX;
	int t1 = 0, t2 = 0;
	for (int i = 0; i < 100; i++)
	{
		if (rrand(0.005)){
			t1++;
			cout << "�н�" << endl;
		}
		else{
			t2++;
			cout << "û�н�" << endl;
		}
	}
	cout << t1 << " " << t2 << endl;
	return 0;
}