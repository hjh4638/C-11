#include <iostream>
using namespace std;

template<typename T, typename ThreadModel> 
class List : public ThreadModel
{
public:
	void push_front(const T& a)
	{
		Lock();
		// ....
		Unlock();
	}
};

// ���� ����(Policy Base) ������ ���
// Ŭ���� ����� ��å�� ���� ��å Ŭ������ ���ø� ���ڷ� 
// ��ü �� �� �ְ� ������ �ϴ� ���
// ���� ���� ���� ��å�� ������ �� �ִ�.
// ��� ��å Ŭ������ ���Ѿ� �ϴ� ��Ģ�� �ִ�. (Lock()/Unlock())

// �����̳��� ����ȭ�� ���� ��å Ŭ����
class NoLock
{
public:
	inline void Lock(){}
	inline void Unlock(){}
};

class MutexLock
{
public:
	inline void Lock(){ cout << "Mutex Lock" << endl; }
	inline void Unlock() { cout << "Mutex Unlock" << endl; }
};
List<int, MutexLock> s1; // �������� - ��Ƽ������ ȯ�濡�� �������� �ʴ�.
List<int, NoLock> s2;

int main()
{
	s1.push_front(10);
}