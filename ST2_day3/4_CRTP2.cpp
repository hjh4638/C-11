#include <iostream>
using namespace std;

// 싱글톤 : 오직 하나의 객체만 생성되게 하는 디자인 패턴

class Cursor
{
private:
	Cursor(){}

	static Cursor* instance;
public:
	// 오직 하나의 객체만 만들어서 리턴하는 정적 함수
	static Cursor& GetInstance()
	{
		if (instance == 0)
		{
			instance = new Cursor;
		}
		return *instance;
	}
};
Cursor* Cursor::instance = 0;

int main()
{
	//Cursor c1, c2;
	Cursor& c1 = Cursor::GetInstance();
	Cursor& c2 = Cursor::GetInstance();

	cout << &c1 << " , " << &c2 << endl;
}