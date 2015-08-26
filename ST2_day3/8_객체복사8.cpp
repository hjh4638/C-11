#include <iostream>
using namespace std;

// �̱��� : ���� �ϳ��� ��ü�� �����ǰ� �ϴ� ������ ����

class Cursor
{
private:
	Cursor(){}

	static Cursor* instance;
public:
	// ���� �ϳ��� ��ü�� ���� �����ϴ� ���� �Լ�
	static Cursor& GetInstance()
	{
		if (instance == 0)
		{
			instance = new Cursor;
		}
		return *instance;
	}

	// �̱����� ����� ������ �����ؾ� �Ѵ�.
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;
};
Cursor* Cursor::instance = 0;

int main()
{
	//Cursor c1, c2;
	Cursor& c1 = Cursor::GetInstance();
	Cursor c2 = c1;
}