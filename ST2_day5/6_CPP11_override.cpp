class Base
{
public:
	virtual void foo(int){}
	virtual void goo() const{}
	void hoo(){}
};

class Derived : public Base
{
public:
	// �����Լ��� ������ �ϰ� �;����ϴ�. �׷���
	// ���� �� �������� �Ǽ��� ��� ������
	/*
	void foo(int){}					//1 ok virtual ��������
	virtual void foo(double){}		//2 �Ķ���� Ÿ�� Ʋ�ȴ�
	virtual void goo(){}			//3 ��� �Լ��� �ƴϴ�
	virtual void gooo(){}			//4 �Լ� �̸� Ʋ�ȴ�
	void hoo(){}					//5 �����Լ��� �ƴϴ�
	*/
	void foo(int) override{}				//1 ok virtual ��������
	virtual void foo(double) override{}		//2 �Ķ���� Ÿ�� Ʋ�ȴ�
	virtual void goo() override{}			//3 ��� �Լ��� �ƴϴ�
	virtual void gooo() override{}			//4 �Լ� �̸� Ʋ�ȴ�
	void hoo()override{}					//5 �����Լ��� �ƴϴ�

	virtual void foo(int) final{}
	// Derived �� �ڽ� Ŭ���� ���ʹ� foo�� ������ �� �� ����.
};

int main()
{

}