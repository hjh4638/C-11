

int square(int a){ return a*a; }
double square(double a){ return a*a; }

//������ �ڵ尡 �ݺ� �Ǹ� �ڵ�����⸦ �������
//1. ��ũ�ο� ���� �ڵ� ���� - ��ó���Ⱑ �ڵ� ����
//	 ���� : ��ó����� Ÿ���� ���� ���Ѵ�.
//		    � Ÿ���� �Լ��� �ʿ������� �̸� �����ؾ� �Ѵ�!!
//#define MAKE_SQUARE(T) T square(T a){return a*a;}
//
//MAKE_SQUARE(int)
//MAKE_SQUARE(double)

//2. �����Ϸ��� ���� �ڵ� ����
//	 �����Ϸ��� ������ �߿� Ÿ���� �� �� �ִ�.
//	 � Ÿ���� �Լ��� �ʿ������� �̸� �˷��� �ʿ䰡 ����.!
template<typename T> T square(T a){ return a*a; }

//template instantiation(�ν��Ͻ�ȭ) : T�� Ÿ���� �����ؼ� 
//									  ���� �Լ��� ����� ����

//�Ͻ��� �ν��Ͻ�ȭ : T�� Ÿ���� �����Ϸ��� ����(�߷�, Deduction)
//					�ؼ� �Լ� ����

//����� �ν��Ͻ�ȭ : T�� Ÿ���� ����ڰ� �����ؼ� �Լ� ����

//Code Bloat : �ʹ��� ���� �Լ�/Ŭ������ �����Ǿ� �ڵ�޸𸮰�
//			   �����ϴ� ����..
int main(){
	//�Ͻ��� �߷�
	square(3);   // int    square(int a){return a*a;} �Լ� ����
	square(3.3); // double square(double a){return a*a;} �Լ� ����

	short s = 3;
	square(s); //short ���� ����

	//������߷�
	square<int>(s);//����ڰ� T�� Ÿ���� ���� - int ������ �����
				   //�޶�
}