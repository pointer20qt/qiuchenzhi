#include<iostream>
#include<time.h>
#include"tool.h"
using namespace std;//怎么生成a~b的随机小数//传入0到100的整数，概率性判断成功,成功返回true//传入0到1的double，概率性判断成功，成功返回turerand()从随机数序列中取下一个    srand(time(0)) 初始化随机数序列
bool rrand(double a){
	//rand()取值（0~RAND_MAX）
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
	////生成[0, a)的数
	rand() % a;
	////生成[a,b)的数	
	rand() % (b - a) + a;
	//生成一个0~1的随机小数double
	((double)rand()) / RAND_MAX;
	int t1 = 0, t2 = 0;
	for (int i = 0; i < 100; i++)
	{
		if (rrand(0.005)){
			t1++;
			cout << "中奖" << endl;
		}
		else{
			t2++;
			cout << "没中奖" << endl;
		}
	}
	cout << t1 << " " << t2 << endl;
	return 0;
}