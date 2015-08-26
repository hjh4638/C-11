#include <iostream>
using namespace std;

template<typename T> class Stack
{
	T buff[100];
	int index;

public:
	Stack() : index(-1){}

	// T는 크기가 큰 객체일 수도 있따.
	// call by value 는 동일 객체를 메모리에 한번 더 생성한다.
	// const T& 가 좋다.
	// void push(T a){buff[++index] = a;}

	void push(const T& a){ buff[++index] = a; };

	// pop()이 제거와 리턴을 동시에 하면 최적화 할 수 없다.
	// 임시객체를 막을 수 없다.
	//T  pop()		{ return buff[index--]; }

	void pop(){ --index; }			  // 제거만
	T&	 top(){ return buff[index]; } // 리턴만
};

// C++에서 template 기반의 컨테이너 (list, stack, vector등)의
// 모든 함수는 제거와 리턴을 동시에 하지 않는다.

// 1. 참조리턴을 통한 임시객체를 제거하기 위해
// 2. 예외 안전성의 강력보장을 위해

int main()
{
	Stack<int> s;
	s.push(10);
	s.push(20);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
}