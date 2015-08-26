template<typename T, typename U> struct Duo
{
	T value1;
	U value2;
	enum{N=2};
};

//Recursive Duo를 사용하기 쉽도록 선형화 하는 코드
struct NullType{};

template<typename P1 =NullType,
	typename P2 = NullType,
	typename P3 = NullType,
	typename P4 = NullType,
	typename P5 = NullType>
class xtuple : public Duo < P1, xtuple < p2, p3, p4, p5, NullType >>
{

};
//xtuple이 2개의 유효한 타입일때를 부분 전문화
template<typename A, typename B>
class xtuple<A, B, NullType, NummType, NullType> : public(부모)
int main()
{
	//					Duo<long, double>
	//				Duo<short, xtuple<long,double,N,N,N>>
	//		   Duo<char,long,double>
	//Duo<int, xtuple<char, short, long, double, N>>
	xtuple<int, char, short, long, double>t5;
	xtuple<int, int, int> t3;
}