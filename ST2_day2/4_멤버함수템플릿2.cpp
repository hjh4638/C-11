class Animal{};
class Dog :public Animal{};

int main()
{
	Dog* p1 = new Dog;
	Animal* p2 = p1; //부모 타입 포인터는 자식의 주소를 담을 수 
					 //있습니다.
	//요즘은 포인터 대신 스마트 포인터를 많이 사용합니다(내일 배움)

	//sp : 안드로이드 프레임워크에 있는 스마트 포인터
	sp<Dog> p1 = new Dog;
	sp<Animal> p2 = p1;

	p2 = p1;
	if (p2 == p1){}
	//스마트포인터에는 반드시 복사/대입/==/!= 가 template 버전으로
	//있어야 합니다
}

//cafe.naver.com/cppmaster에서 예전 수업 자료실에서 kitkat 검색해보세요.
//core/include/utils/strongpointer.h