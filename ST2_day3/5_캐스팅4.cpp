#include <iostream>
using namespace std;

// dynamic_cast는 가상함수 테이블에 있는 type 정보를 사용합니다.
// 그래서 가상함수가 반드시 1개 이상 있어야 합니다.

// C++ 기본 : 모든 부모의 소멸자는 가상함수 이어야 한다.
//			라는 규칙이 있으므로 대부분 한개 이상의 가상함수는 있습니다.
class Animal{
public:
	virtual ~Animal(){}
};

class Dog : public Animal
{
public:
	int color;
};
//-----------------------------
// 모든 동물에 공통의 기능만 수행한다면 부모인 Animal*를 인자로!!
void foo(Animal* p)
{
	// 모든 동물의 공통 기능 수행후

	// Dog라면 색상도 변경
	//p->color = 10; // p가 Animal* 이므로 color는 없다

	// 다운(Down) 캐스트 : 부모 포인터 => 자식포인터로 변경하는것
	// static_cast : 다운 캐스트 할 때 정말 Dog인지를 확인 할 수없다.
	//				 컴파일 시간에는 메모리를 조사할 수 없으므로!!
	// Dog* pDog = static_cast<Dog*>(p);

	// 실행시간에 p가 가리키는 메모리를 조사해서 Dog가 맞는 경우만
	// 성공. 아니면 0 리턴
	Dog* pDog = dynamic_cast<Dog*>(p);
	cout << pDog << endl;
	
	if (pDog !=0)
		pDog->color = 10;
}

void goo(Animal* p){} // 공통작업만

// Dog를 위한 작업을 추가하려면 위의 goo를 변경하지 말고
// 아래처럼 만드는 것이 좋은 디자인
void goo(Dog* p)
{
	goo(static_cast<Animal*>(p));

	// Dog 만의 작업
}
int main()
{
	//Dog d;	foo(&d);
	Animal a; foo(&a);
}