int main()
{
	int n = 10;
	
	// ��� �޸𸮰� ����ΰ� ?
	//const int* p1 = &n; // p1�� ���󰡸� const�� �ִ�
	int* const p2 = &n; // p2�� ���󰡸� const�� �ƴϴ�
						// ������, p2 ��ü�� const�̴�.
						// �ʱ�ȭ�� ����
	p2 = &n2; // error
	*p2 = 20; // ok

	// �Ʒ� 2���� ����
	int const* p3 = &n; // p1�� ����
	const int* p1 = &n;
}

// this�� �����
class Point
{
	int x, y;
public:
	void Set() // void Set( Point* const this )
	{
		x = 0; // this->x = 0;
		y = 0; // this->y = 0;

		this = 0;// error. this ������ ��ü�� ����̴�.
		x = 0;
	}

	void print() const // void print( const Point* const this )
	{
		x = 0; // this->x = 10;
	}
}