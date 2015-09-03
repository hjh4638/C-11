#include <iostream>
using namespace std;

// �̱۸���Ʈ�� ������ ���ô�.
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
	
	// �Ʒ� ó�� Node�� �����ڸ� �� Ȱ���ϸ� �̱۸���Ʈ �ڵ带
	// �����ϰ� ���� �� �ֽ��ϴ�.
	void push_front(T const& a){ head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30); // �� ������ �޸� ��� ������ ������.
}