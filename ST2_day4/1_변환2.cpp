#include <iostream>
using namespace std;

// ��ȯ�� �����

// ������ �Ҹ��ڷ� �ڿ��� �����ϸ� ���ϴ�
// RAII(Resource Acquision Is Initialize)��� �̸��� ���� ���

class OFile
{
	FILE* file;
public:
	// explicit : ���ڰ� �Ѱ��� �����ڰ� �Ͻ��� ��ȯ�� ����Ű��
	//			  ���� ���´�.
	//			  ��, ����� ��ȯ�� ����Ѵ�.
	explicit OFile(const char* name, const char* mode = "wt")
	{
		file = fopen(name, mode);
	}
	~OFile(){ fclose(file); }
	operator FILE*()
	{
		return file;
	}
};
void foo(OFile f){}
int main()
{
	OFile f;
	foo(f); // ok.. �翬�ϴ�!!

	foo("hello"); // ???? ������ ������ ���� �ʴ´� ?? �� ?
				// const char* => OFile�� ��ȯ�Ǹ� ok

	foo(static_cast<OFile>("hello")); // ok.. ����� ��ȯ
}

/*
int main()
{
	OFile f("a.txt");

	// ���� IO �۾�
	fprintf(f, "n=%d", 10);
	fputs("hello", f);

	String s1 = "hello"; // string Ŭ����

	char s2[10];

	strcpy(s2, s1); // �Ǵ°� �������? �ȵǴ°� �������?
					// String => const char*�� ��ȯ�Ǿ�� �Ѵ�.
}
*/