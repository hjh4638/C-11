// T�� ������� ���� ��� ��� �Լ��� �θ� Ŭ������ �����.
// �θ� �Լ� 2�� + �ڽ� �Լ� 2�� * 3�� Ÿ�� => 8�� �Լ�
class VectorImpl
{
	int sz;
public:
	int size(){ return sz; }
	bool empth(){ return sz == 0; }

};
template<typename T> class Vector : public VectorImpl
{
	T buffer[100];
public:
	void push_front(T a){}
	T front(){ return buffer[0];}
};

int main()
{
	Vector<int> v1;
	Vector<char> v2;
	Vector<double> v3; // Vector�� ����Լ��� � �ϱ�� ?
}