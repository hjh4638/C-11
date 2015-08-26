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

// 단위 전략(Policy Base) 디자인 기술
// 클래스 설계시 정책을 담을 정책 클래스를 템플릿 인자로 
// 교체 할 수 있게 디자인 하는 기술
// 성능 저하 없이 정책을 변경할 수 있다.
// 모든 정책 클래스는 지켜야 하는 규칙이 있다. (Lock()/Unlock())

// 컨테이너의 동기화를 위한 정책 클래스
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
List<int, MutexLock> s1; // 전역변수 - 멀티스레드 환경에서 안전하지 않다.
List<int, NoLock> s2;

int main()
{
	s1.push_front(10);
}