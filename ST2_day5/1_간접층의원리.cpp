// 1.�������� ����

// �ƹ��� ����� S/W �������� �߰���(���� ��� ���̿� ���ο� ���)
// �� �����ϸ� �ذ��� �� �ִ�.
// "Level Of Indirection" �̶�� ����

// ������Ҹ� ����Ѵٴ� �ǹ̷� "Proxy" �����̶�� �θ��� �����α��
struct VectorSize
{
	int size;
	VectorSize(int n) // int => VectorSize�� �Ͻ��� ��ȯ�ȴ�.
		: size(n){}
};

class Vector
{
public:
	//Vector(int sz){}
	Vector(VectorSize sz){ // VectorSize => Vector�� �Ͻ��� ��ȯ�ȴ�.
		int size = sz.size;
	}
};

void foo(Vector v){}

int main()
{
	Vector v(10);
	foo(v); // ok



	foo(20); // ???? int => Vector ��, ��ȯ�����ڰ� ������ OK..
}