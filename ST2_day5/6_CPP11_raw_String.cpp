#include <iostream>
#include <string>
using namespace std;

int main()
{
	// ���ڿ����� "\\"�� ����ϰ� ���� �� => "\\" �ؾ� �մϴ�.
	string s = "C:\\AAA\\BB";

	cout << s << endl;

	// "\"�� �ѹ��� ���� �� �ִ� ǥ����

	// R"(   )"

	// )" �� ������ �ĺ����̹Ƿ� "�� �׳� ������ �˴ϴ�.
	char s2[] = R"(C:\AA"A\BB)";
	char s3[] = R"("aaa"""aaaa"\sd1\!@3)";
	cout << s2 << endl;
	cout << s3 << endl;

	// ������ : ���ڿ� �߰��� )"�� ǥ���ϰ� ���� ��

	//char s4[] = R"(AAA)"BBB)"; // error

	// �ذ�å
	// �⺻ �ĺ��� : "(   )" �ε� "�� ( ���̿� ����ڰ� �߰�����
	//				 "***(   )***" �ε�

	char s5[] = R"***( AAA)"BBB)***";

	cout << s5 << endl;
	cout << strlen(s5) << endl;
}