//�� Ŭ���� ���ø��� ��� �Լ� ���ø��� ����ϴ°� ??

//1. complex�� ���ø����� ����� ����
//	 double�̸� �ɰ� ������ double�� �����ϴ�.

//2. Zero Initialize : T a = T()
//	 T�� ǥ�� Ÿ���̰ų� ������ �̸� 0���� �ʱ�ȭ
//	 T�� ����� Ÿ���̸� ����Ʈ �����ڷ� �ʱ�ȭ

template<typename T>
class complex
{
	T re;
	T im;
public:
	complex(T r = T(), T i = T()) : re(r), im(i){}
	//�Ϲ�ȭ�� (generic) ���������
	//U�� T�� ����(����)�ɼ� �ִٸ�
	//complex<U>�� complex<T>�� ���� �� �� �־�� �Ѵ�.
	//=>�Ϲ�ȭ�� ���������(���Կ�����)�� �ʿ��ϴ�!
	template<typename U> complex(const complex<U>& c);

	//��� Ÿ���� complex ���� ���� private�� ���� �����ؾ� �Ѵ�.
	//friend void foo(); // friend �Լ�
	template<typename U> friend class complex;
};
//�Ϲ�ȭ�� ����������� �ܺ� ����
template<typename T> template<typename U>
complex<T>::complex(const complex<U>& c) :re(c.re), im(c.im)
{

}

int main()
{
	complex<int> c1(1.1, 2.2);
	complex<int> c2 = c1;
	complex<double> c3 = c1;
}