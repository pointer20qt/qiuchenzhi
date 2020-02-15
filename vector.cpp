#include<iostream>
#include<vector>
using namespace std;

template <class T>class L_stack{
	std::vector<T> arr;
public:
	void push(T&& obj){
		arr.push_back(obj);
	}
	void pop(){
		arr.pop_back();
	}
	T& top(){
		return arr.back();
	}
	size_t size(){
		return arr.size();
	}

};
template<class T, class...args>void Lprint(T f, args...d){
	cout << f << endl;
	Lprint(d...);
}
void Lprint(){
	cout << "µÝ¹é²ð°ü½áÊø" << endl;
}
int main()
{
	//L_stack<int> l;
	//l.push(2);
	//l.push(3);
	//cout << l.top() << endl;
	//l.pop();
	Lprint(1, 3, 5, 7, "123");
	return 0;
}