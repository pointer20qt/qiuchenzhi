#include<iostream>
#include<initializer_list>
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
int main()
{
	vec v = { 1, 2, 3, 4, 5, 6 };
	cout << v[2] << endl;
	v[2] = 5;
	cout << v[2] << endl;
}