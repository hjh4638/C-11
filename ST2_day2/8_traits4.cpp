//�������� ��츦 ó���ϴ� �Լ�
template<typename> void printv_imp(T a, YES)
{
	cout << a << ", " << a << endl;
}


//�����Ͱ� �ƴ� ���
template<typename T> void printv_imp(T a, NO)
{
	cout << a << endl;
}

//����ڰ� ����ϴ� ����
template<typename T> void printv(T a)
{
	//printv_imp(a, T is Pointer ? );

	//if���� ����ð��Դϴ�. �׷��� �Ʒ� �ڵ�� ����ð� �Լ���
	//���õ˴ϴ�.
	//�׷��� �����Ϸ��� YES ������ No ������ ��� �Լ� ���ø���
	//�ν��Ͻ�ȭ �ϰ� �˴ϴ�. 
	//�ᱹ �������� ��� YES �������� error �߻�.
	if (T is Pointer)
		printv_imp(a, YES);
	else
		printv_imp(a, NO);

	//�Լ� �����ε��� ������ �ð� �Լ� �����Դϴ�.
	//��, int�� ��� YES ������ ������ ���� �ʽ��ϴ�.
	printv_imp(a, T is Pointer);
}

int main
{
	int n = 3;
	printv(n);
}