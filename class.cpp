#include<iostream>
using namespace std;

//类模板
template<class T> T Lmax(T a, T b){
	cout << "模板函数" << endl;
	return a > b ? a : b;
}
class A{
public:
	int value = 0;
	char *p;
	A(int val){
		p = new char[100];
		value = val;
	}
	bool operator>(A&){
		return true;
	}
	//重载一个类型
	operator int(){
		cout << "转化为int类型" << endl;
		return value;
	}
	A(const A& other) :A(other.value){
		p = new char[100];
		value = other.value;
		cout << "拷贝构造" << endl;
	}
	A& operator=(const A& other){
		delete p;
		p = new char[100];
		value = other.value;
		return *this;
	}
	~A()
	{
		delete p;
	}
};
A Lmax(A a, A b)
{
	
	return a > b ? a : b;
}
int Lmax(int a, int b)
{
	cout << "int类型模板函数" << endl;
	return a > b ? a : b;
}

template <class T> void Lswap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
//int main(){
//	int x1 = 1, x2 = 5;
//	double y1 = 2.5, y2 = 2.3;
//	////显式推导
//	cout << Lmax<double>(x1, y1) << endl;
//	////隐式推导
//	cout << Lmax(x1, x2) << endl;
//	////显式指定模板推导
//	cout << Lmax<>(x1, x2) << endl;
//	Lswap(x1, x2);
//	cout << x1 << "交换函数" << x2 << endl;
//	A a(20), b(32);
//	int c = a;
//	Lswap(a, b);
//	cout << a << " " << b << " " << c << endl;
//	return 0;
//}