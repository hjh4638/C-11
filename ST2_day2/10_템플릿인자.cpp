//1. type
//2. ������ ���(���� �ȵ�. �Ǽ��ȵ�)
template<typename T = int, int N = 10> struct stack
{
	T buff[N];
};
int main()
{
	stack<int, 10> s1;
	int n = 10;
	//stack<int, n> s2; //error. ������ �ð� ����� ����.

	stack<int> s3; //N�� 10
	stack<> s3; //��� ���ڸ� ����Ʈ������
}