//#include <iostream>
//using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	// �Է� ������ �����ϴ� ��� 1. fail() ��� �Լ�
	if (cin.fail()){}

	// 2. cin ��ü�� if�� ���� - ������ ����� ?
	if (cin) // cin.operator void*() �� �ֱ� ������ �����ϴ�
	{
		cout << "����" << endl;
	}
}

// cin�� istream Ŭ�����Դϴ�. jerry schwarz ��� �����ڰ�
// ��������ϴ�.

void true_function(){}
class istream
{
	class dummy
	{
	public:
		void true_function(){}
	};
public:
	bool fail(){}

	//operator bool(){ return fail() ? false : true; }
	//operator void*(){ return fail() ? 0 : this; }
	//typedef void(*PF)();
	//operator PF(){ return fail() ? 0 : &true_function; }

	typedef void(dummy::*PF)();
	operator PF(){ return fail() ? 0 : &dummy::true_function; }
};
istream cin;

// cin�� scalar test �ϰ� �;����ϴ�. if ( cin ) ..

// 1. bool�� ��ȯ�Ǹ� �ȴ�... �׷���
cin << n; // cin�� bool�� ���ϸ� << �����ڰ� shift �����ڷ� 
		// �νĵǾ ������ ���� �ʴ´�

// 2. if()�� ���̴µ� <<�� ������ ���� �ߴ� -> �����ͷ� ��ȯ
//	  �׷���. boost�������� �Ʒ� �������� �����Ѵ�.
delete cin; // ������ �� �� ������ ���� �ʴ´�.

// 3. if() ���̰� �ʹ�. shift���� �Ұ���. delete �ȵǾ� �Ѵ�.
//	  �Լ������ͷ� ��ȯ����... �׷���..
void(*f)() = cin; // �� ������ ���� �ʴ���...

// 4. if()�� ���� �� ������.. �ִ��� side effect�� ���̰� �;���
// 