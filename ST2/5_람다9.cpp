

//���ٿ� ����Ÿ��
int main(){
	auto f1 = [](int a, int b){return a + b; };
	auto f2 = [](int a, int b){
		if (a > b)
			return a;
		else
			return b; 
	};
	// ���� Ÿ���� ���� () �ڿ� ���� ���� - traling return
	// 
	auto f3 = [](int a, int b)-> int{
		if (a > b)
			return a;
		else
			return 3.0;
	};
}