//포인터인 경우를 처리하는 함수
template<typename> void printv_imp(T a, YES)
{
	cout << a << ", " << a << endl;
}


//포인터가 아닌 경우
template<typename T> void printv_imp(T a, NO)
{
	cout << a << endl;
}

//사용자가 사용하는 버전
template<typename T> void printv(T a)
{
	//printv_imp(a, T is Pointer ? );

	//if문은 실행시간입니다. 그래서 아래 코드는 실행시간 함수가
	//선택됩니다.
	//그래서 컴파일러는 YES 버전과 No 버전의 모든 함수 템플릿을
	//인스턴스화 하게 됩니다. 
	//결국 포인터인 경우 YES 버전에서 error 발생.
	if (T is Pointer)
		printv_imp(a, YES);
	else
		printv_imp(a, NO);

	//함수 오버로딩은 컴파일 시간 함수 선택입니다.
	//즉, int일 경우 YES 버전은 컴파일 되지 않습니다.
	printv_imp(a, T is Pointer);
}

int main
{
	int n = 3;
	printv(n);
}