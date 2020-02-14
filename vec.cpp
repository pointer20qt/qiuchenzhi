#include<iostream>
#include<initializer_list>
//#define NDEBUG 在<assert.h>前定义可以取消断言
#include<assert.h>
#include<vector>
static_assert(sizeof(int)!=32,"inappropriate int size");
using namespace std;

class vec{
	int *obj;
public:
	vec(initializer_list<int> arr)
	{
		obj = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++)
		{
			obj[i] = *(arr.begin() + i);
		}
		//for (auto i = arr.begin(); i != arr.end(); i++)
		//{
		//	cout << *i << endl;
		//}
	}
	int& operator[](unsigned int i){
		return obj[i];
	}

};
class vec2{
	vector<int> arr;
public:
	vec2(initializer_list<int> list) :arr(list){
	}
	int &operator[](int index){
		//assert(index > 0 && index < arr.size());
		return arr[index];
	}
};
int main()
{
	vec2 v = { 1, 2, 3, 4, 5, 6 };
	cout << v[-2] << endl;
	cout << v[2] << endl;
	cout << v[4] << endl;
	cout << v[5] << endl;
	cout << v[3] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;

}