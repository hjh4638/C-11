#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 문자열에서 "\\"를 사용하고 싶을 때 => "\\" 해야 합니다.
	string s = "C:\\AAA\\BB";

	cout << s << endl;

	// "\"를 한번만 적을 수 있는 표현식

	// R"(   )"

	// )" 가 끝나는 식별자이므로 "는 그냥 적으면 됩니다.
	char s2[] = R"(C:\AA"A\BB)";
	char s3[] = R"("aaa"""aaaa"\sd1\!@3)";
	cout << s2 << endl;
	cout << s3 << endl;

	// 문제점 : 문자열 중간에 )"를 표현하고 싶을 때

	//char s4[] = R"(AAA)"BBB)"; // error

	// 해결책
	// 기본 식별자 : "(   )" 인데 "와 ( 사이에 사용자가 추가가능
	//				 "***(   )***" 인데

	char s5[] = R"***( AAA)"BBB)***";

	cout << s5 << endl;
	cout << strlen(s5) << endl;
}