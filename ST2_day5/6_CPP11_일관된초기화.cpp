
struct Point{ int x, y; };
struct Complex
{ 
	int x, y; 
public:
	Complex(int x, int y) : x(x), y(y){}
};

int main()
{
	/*
	int n1 = 0;
	int n2(0);

	int x[10] = { 0, };
	Point p = { 1, 1 };

	Complex c(0, 0);
	*/

	// Uniform intialize : ������ ������ ������� ������ ������� 
	//						�ʱ�ȭ �� �� �ְ� ����!!
	int n1{ 0 };
	int n2{ 0 };
	int x[10]{0};
	Point p{ 1, 1 };
	Complex c{ 0, 0 };

	int n3 = 3.4;  // ok... C���� ȣȯ�� ������ C++�� �����ϱ�� ����
	
	//int n4{ 3.4 }; // error. preventing narrow

	char c{ 300 }; // error. 300�� 1byte�� ǥ���� �� ����.
	char c2{ 200 };// ok..
}