#include <iostream>
#include <string>
using namespace std;

/*
// string Ŭ������ ����� �Ʒ��� �����մϴ�.
template<typename T,			// UNICODE ���
		 typename traits,	// ���� ����
		 typename Alloc>		// �޸� �Ҵ��
class basic_string
{
	Alloc alloc;
public:
	bool operator==(const basic_string& s)
	{
		// �ΰ��� ���ڿ� ���ϱ�
		return traits::cmp(buff, s.buff);
	}
};
typedef basic_string<char, char_traits<char>, allocator<char>> string;

*/

// basic_string �� ����� �� ���� ����
// ���� ���� ���� �� �Ϻ� �Լ��� ��å�� �����Ϸ���
// ���� ���������� �ڽ����� ���� �˴ϴ�.
struct my_traits : public char_traits<char>
{
	static bool eq(char a, char b){ return toupper(a) == toupper(b); }
	static bool lt(char a, char b){ return toupper(a) < toupper(b); }
	static bool gt(char a, char b){ return toupper(a) > toupper(b); }
	static bool compare(const char* a, const char* b, int sz)
	{
		cout << "cmp" << endl;
		return memicmp(a, b, sz); 
	}
};

typedef basic_string<char, my_traits, allocator<char>> my_string;


int main()
{
	my_string s1 = "ABCD";
	my_string s2 = "abcd";
	
	if (s1 == s2)
		cout << "Same" << endl;
	else
		cout << "not same" << endl;
}