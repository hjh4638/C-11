
// Sort( ... Less()) ���� ǥ���� ó��. �ӽð�ü�� ���ڷ� ��������
// �� �Ǵ� const ���� �� �޾ƾ� �Ѵ�.
// const ������ �Լ���ü�� ����Ϸ��� ()�����ڰ� ����Լ��̾�� �Ѵ�.

// �Լ� ��ü�� ���� �� �ǵ����̸� ����Լ��� ����!!!
struct Less
{
	bool operator()(int a, int b) const{ return a < b; }
};

template<typename T>
void Sort(int* x, int n, const T& cmp)
{
	cmp(x[0],x[1]);
}

int main()
{
	int x[10] = { 0, };
//	Less f1;
//	Sort(x, 10, f1);

	Sort(x, 10, Less()); // ����鼭 ���ڷ� ���� - �ӽð�ü
}