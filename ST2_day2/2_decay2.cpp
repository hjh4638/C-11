//template<typename T> void foo(T a, T b)
template<typename T> void foo(T& a, T& b)
{
}

//T&�� ���鶧 ���ڿ��� ������ ȥ�������� �� �� �ִ�.
//�̰��� ���ڿ� ���� ������ ����� �ȴ�.
//�Լ� ã�� ����
//1. ��Ȯ�� Ÿ�� : ���ڿ� �迭������ �Լ�
//2. ��ȯ ������ Ÿ�� : ���ڿ� ������ ������ �Լ�
//3. template ���
//4. �������� ���
//5. error
void foo(char* s1, char* s2)
{

}
int main(){
	foo("orange", "apple");
}