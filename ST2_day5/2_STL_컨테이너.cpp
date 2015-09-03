#include <iostream>
using namespace std;

// 싱글리스트를 생각해 봅시다.
template<typename T> struct Node
{
	T		data;
	Node*	next;
	Node(T a, Node* n) : data(a), next(n){}
};

template<typename T> class slist
{
	Node<T>* head;
public:
	slist() : head(0){}
	
	// 아래 처럼 Node의 생성자를 잘 활용하면 싱글리스트 코드를
	// 간단하게 만들 수 있습니다.
	void push_front(T const& a){ head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30); // 이 순간의 메모리 모양 생각해 보세요.
}