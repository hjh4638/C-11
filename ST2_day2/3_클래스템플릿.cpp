template<typename T> class stack
{
	T buff[100];
	int index;
public:
	//�����ڷ� �´� ����?
	stack()	  {}//1 ok..
	stack<T>(){}//2 �Ϻ� �����Ϸ��� �� ǥ���� ���.
				// ������ 1���� ��Ȯ�� ǥ��

	//���� ������
	stack(const stack& s)   {} //1 Ŭ���� ���ο��� ���
							   //�� �ܺ� �����ÿ��� �� ǥ���� ����
	stack(const stack<T>& s){} //2 ��Ȯ�� ǥ��

	//��� �Լ��� �ܺα���
	void push(T a);

	//static ��� data�� �ܺ� ����
	static int count;

	//��� �Լ� ���ø�
	template<typename U> T foo(U a);
};
//template <typename T, typename U> //,���� stack<T, U> �� �����ؼ� �ȵ�

//Ŭ���� ���ø��� ��� �Լ� ���ø��� �ܺ� ������ ���
template<typename T> template<typename U> T stack<T>::foo(U a)
{

}

//static ��� data�� �ܺ� ����
template<typename T> int stack<T>::count = 0;
template<typename T>
void stack<T>::push(){T a}
{

}

int main()
{
	stack	   s1; //error. stack�� Ÿ���� �ƴ϶� Ʋ(template)�̴�.
	stack<int> s2; //ok.	stack<int>�� Ÿ���̴�.
}