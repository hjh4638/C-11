
int main()
{
	// �츮�� ���� slist�� ������ ���ô�.

	slist<int> s;
	s.push_front(10);
	s.push_front(10);

	slist<int>::iterator p = s.begin();
	++p; // ok
	--p; // ?? �ɱ�� ? ���������δ� ���� ������
		 // �̱۸���Ʈ��� �ڷ� ���� Ư���� ���� �� ����.
}