//������ �ν��Ͻ�ȭ(lazy instantiation)
//������ ���� �Լ� (����Լ�) ���ø��� �ν��Ͻ�ȭ(�����Լ���) ���� 
//�ʴ´�.
//�� ������ ����� ����� ���� ���� �ֽ��ϴ�.

class aaa{
public:
	void foo(int a)
	{
		*a = 10;
	}
};

//template<typename T> class AAA
//{
//public:
//	void foo(T a)
//	{
//		*a = 10;
//	}
//};

int main(){
	AAA<int> aaa;
	//aaa.foo(0);
}