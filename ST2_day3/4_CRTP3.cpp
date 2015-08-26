#include <iostream>
using namespace std;

// 싱글톤 : 오직 하나의 객체만 생성되게 하는 디자인 패턴

template<typename T> class Singleton
{

protected:
	Singleton(){}
	static T* instance;
public:
	// 오직 하나의 객체만 만들어서 리턴하는 정적 함수
	static T& GetInstance()
	{
		if (instance == 0)
		{
			instance = new T;
		}
		return *instance;
	}
};
template<typename T> T* Singleton<T>::instance = 0;

//---------------
//마우스도 싱글톤으로 만들고 싶다.
class Mouse : public Singleton<Mouse>
{
};

int main()
{
	Mouse& m = Mouse::GetInstance();

	cout << &m << endl;
}