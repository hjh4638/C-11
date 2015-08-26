// �̹� C++ ǥ�ؿ� list�� �ֽ��ϴ�.
#include <list>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

// �׷��� stack�� �ʿ��մϴ�.
// 1. stack �ٽ� ������
// 2. list�� ��������

// Adapter ������ ���� : ���� Ŭ������ �������̽�(�Լ� �̸�)�� 
//						�����ؼ� Ŭ���̾�Ʈ�� �䱸�ϴ� ���ο� Ŭ������
//						����� ����
//						C++�� ���ø��� �ζ������� �������Ͼ���
//						������� �ִ�
/*
template<typename T> class stack :public list < T >
{
public:
	inline void push(const T& a){ list<T>::push_back(a); }
	inline void pop()			 { list<T>::pop_back(); }
	inline T&	 top()			 { return list<T>::back(); }
};
*/

// S/W ������ ��� vs ������ �ִ�.
// ������ �� ���� ��찡 �� ����.
/*
template<typename T, typename C = deque<T>> class stack
{
	C st;
public:
	inline void push(const T& a){ st.push_back(a); }
	inline void pop()			 { st.pop_back(); }
	inline T&	 top()			 { return st.back(); }
};
*/
int main()
{
	//���� 3. queue adapter ��������
	stack<int> st;
	stack<int, list<int>> st1; // list<int>�� stack ���� �ٲ�޶�
	stack<int, vector<int>> st2;
	
	st.push(10);
	//st.push_front(20); // ����ڰ� �Ǽ� �ߴ�
}