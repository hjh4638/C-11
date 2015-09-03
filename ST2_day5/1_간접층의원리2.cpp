#include <iostream>
using namespace std;

// C++ Programming Language å 13�忡 �Ʒ� ������ ��ü �ڵ尡 �ֽ��ϴ�.
// �� Stroustup
class String
{
	char* buf;
	int* ref; // ���� ���
public:
	String(char const* s)
	{
		buf = new char[strlen(s) + 1];
		strcpy(buf, s);
		ref = new int(1);
	}
	String(String const& s)
	{
		buf = s.buf;
		ref = s.ref;
		++(*ref);
	}
	~String()
	{
		if (--(*ref) == 0)
		{
			delete[] buf;
			delete ref;
		}
	}

	// ������ �ذ��ϱ� ���� ���ο� ��Ҹ� �����Ѵ�.
	// char �� ����ϴ� ��Ҹ� ������
	class CharProxy
	{
		String& str;
		int index;
	public:
		CharProxy(String& s, int n) : str(s), index(n){}

		// Proxy �� char�� ���� �� �־�� �Ѵ�.
		operator char()
		{
			cout << "�д� �۾���. ���纻 �ʿ� ����" << endl;
			return str.buf[index];
		}
		// Proxy�� char�� ������ �� �־�� �Ѵ�.
		CharProxy& operator=(char c)
		{
			cout << "���� �۾���. ���纻�� ������ �Ѵ�" << endl;
			
			// ���� ���纻
			char* temp = new char[strlen(str.buf) + 1];
			strcpy(temp, str.buf);

			if (--(*str.ref) == 0)
			{
				delete[] str.buf;
				delete str.ref;
			}
			str.buf = temp;
			str.ref = new int(1);

			str.buf[index] = c;
			return *this;
		}
	};
	CharProxy operator[](int n)
	{
		cout << "operator[]" << endl;
		return CharProxy(*this, n);
	}
	/*
	// [] ������ ������ : ��ü�� �迭ó�� ��밡���ϰ� �Ѵ�.
	// s[0] = 'a' ó�� [] ȣ���� lvalue�� ���� �Ϸ���
	// ���� �����ؾ� �Ѵ�.
	char& operator[](int n)
	{
		cout << "operator[]" << endl;
		return buf[n]; 
	}
	*/
	void print() const { cout << buf << endl; }
};

int main()
{
	String s1 = "hello";
	String s2 = s1; //�� �����غ�����.

	char c = s1[0]; // �д� �۾��̴�. �ڿ�(���ڿ�)�� ��� �����Ǿ��
					//�Ѵ�.
	cout << c << endl; // 'h'

	s1[0] = 'x'; // ���� �۾��̴�. �ڿ��� �и��ϰ� �����ؾ��Ѵ�
				 // Copy On Write

	s1.print(); // "xello"
	s2.print(); // "hello"
}