#include <iostream>
using namespace std;

// �̱��� : ���� �ϳ��� ��ü�� �����ǰ� �ϴ� ������ ����

template<typename T> class Singleton
{

protected:
	Singleton(){}
	static T* instance;
public:
	// ���� �ϳ��� ��ü�� ���� �����ϴ� ���� �Լ�
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
//���콺�� �̱������� ����� �ʹ�.
class Mouse : public Singleton<Mouse>
{
};

int main()
{
	Mouse& m = Mouse::GetInstance();

	cout << &m << endl;
}