#include <iostream>
using namespace std;

//privary template
template<typename T> class stack
{
	T buff[100];
public:
	void push()
	{
		cout << "T" << endl;
	}
};

//partial specialization(�κ� ����ȭ, �κ� Ưȭ)
template<typename T> class stack<T*>
{
	T buff[100];
public:
	void push()
	{
		cout << "T*" << endl;
	}
};

//specialization (����ȭ)
template<> class stack<char*>
{
	char* buff[100];
public:
	void push()
	{
		cout << "char*" << endl;
	}
};

int main()
{
	stack<int>   s1; s1.push();
	stack<int*>  s2; s2.push();
	stack<char*> s3; s3.push();

}