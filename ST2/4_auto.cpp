

int x = 10;
int& foo(){ return x; }

int main(){
	int n1 = 10;
	int n2 = n1;

	auto n2 = n1; //우변의 타입으로 좌변 변수 타입을 컴파일 시간에 결정해달라


	decltype(n1) n2;// n1의 타입으로 n2를 만들어 달라.

	auto n3 = foo();// int? int& 중 뭘까요?
					// int
	decltype(foo()) n4 = foo(); // int&
								
}