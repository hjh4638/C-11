class AAA{
public:
	//....
	//static int DWORD;
	typedef int DWORD;
};
int p = 0;

//���ø��ȿ� �ִ� Ÿ���� �������� �ݵ�� typename�� ����� �մϴ�.

typename T::DWORD a;

//���ø��� �ƴҶ��� ����ϸ� �ȵ˴ϴ�.
typename AAA::DWORD a;//error. AAA�� ���ø��� �ƴϰ� �Ϲ� Ÿ��!

template<typename T> void foo(T a)
{
	typename T::DWORD *p; //�� ������ �ؼ��� ������
				//1. DWORD�� static ��� data�̴�.
				//���ϱ� p�� �ϰ� �ִ�
				//2. DWORD�� typedef������ ���� Ÿ�Դϴ�.
				// ������ ���� p�� �����ϰ� �ִ�
}
int main(){
	AAA aaa;
	foo(aaa);
}