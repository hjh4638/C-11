#include <iostream>
using namespace std;

// Step1. C�� strchr() �Լ�

char* xstrchr(char* s, char c)
{
	while (*s != 0 && *s != c)
		++s;
	return *s == 0 ? 0 : s;
}
int main()
{
	char s[] = "abcdefgh";

	char* p = xstrchr(s, 'c');
	
	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
}