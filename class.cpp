#include<iostream>
using namespace std;

//��ģ��
template<class T> T Lmax(T a, T b){
	cout << "ģ�庯��" << endl;
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
	//����һ������
	operator int(){
		cout << "ת��Ϊint����" << endl;
		return value;
	}
	A(const A& other) :A(other.value){
		p = new char[100];
		value = other.value;
		cout << "��������" << endl;
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
	cout << "int����ģ�庯��" << endl;
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
//	////��ʽ�Ƶ�
//	cout << Lmax<double>(x1, y1) << endl;
//	////��ʽ�Ƶ�
//	cout << Lmax(x1, x2) << endl;
//	////��ʽָ��ģ���Ƶ�
//	cout << Lmax<>(x1, x2) << endl;
//	Lswap(x1, x2);
//	cout << x1 << "��������" << x2 << endl;
//	A a(20), b(32);
//	int c = a;
//	Lswap(a, b);
//	cout << a << " " << b << " " << c << endl;
//	return 0;
//}