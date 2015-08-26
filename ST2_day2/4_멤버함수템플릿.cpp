//왜 클래스 템플릿의 멤버 함수 템플릿을 사용하는가 ??

//1. complex를 템플릿으로 만드는 이유
//	 double이면 될거 같지만 double은 느립니다.

//2. Zero Initialize : T a = T()
//	 T가 표준 타입이거나 포인터 이면 0으로 초기화
//	 T가 사용자 타입이면 디폴트 생성자로 초기화

template<typename T>
class complex
{
	T re;
	T im;
public:
	complex(T r = T(), T i = T()) : re(r), im(i){}
	//일반화된 (generic) 복사생성자
	//U가 T로 복사(대입)될수 있다면
	//complex<U>는 complex<T>로 복사 될 수 있어야 한다.
	//=>일반화된 복사생성자(대입연산자)가 필요하다!
	template<typename U> complex(const complex<U>& c);

	//모든 타입의 complex 들은 서로 private에 접근 가능해야 한다.
	//friend void foo(); // friend 함수
	template<typename U> friend class complex;
};
//일반화된 복사생성자의 외부 구현
template<typename T> template<typename U>
complex<T>::complex(const complex<U>& c) :re(c.re), im(c.im)
{

}

int main()
{
	complex<int> c1(1.1, 2.2);
	complex<int> c2 = c1;
	complex<double> c3 = c1;
}