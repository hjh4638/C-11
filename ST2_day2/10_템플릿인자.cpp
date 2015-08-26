//1. type
//2. 정수형 상수(변수 안됨. 실수안됨)
template<typename T = int, int N = 10> struct stack
{
	T buff[N];
};
int main()
{
	stack<int, 10> s1;
	int n = 10;
	//stack<int, n> s2; //error. 컴파일 시간 상수만 가능.

	stack<int> s3; //N은 10
	stack<> s3; //모든 인자를 디폴트값으로
}