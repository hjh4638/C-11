

//람다와 리턴타입
int main(){
	auto f1 = [](int a, int b){return a + b; };
	auto f2 = [](int a, int b){
		if (a > b)
			return a;
		else
			return b; 
	};
	// 리턴 타입의 인자 () 뒤에 적는 문법 - traling return
	// 
	auto f3 = [](int a, int b)-> int{
		if (a > b)
			return a;
		else
			return 3.0;
	};
}