template<typename T, typename U> struct Duo
{
	T value1;
	U value2;
	enum{N=2};
};

//Recursive Duo�� ����ϱ� ������ ����ȭ �ϴ� �ڵ�
struct NullType{};

template<typename P1 =NullType,
	typename P2 = NullType,
	typename P3 = NullType,
	typename P4 = NullType,
	typename P5 = NullType>
class xtuple : public Duo < P1, xtuple < p2, p3, p4, p5, NullType >>
{

};
//xtuple�� 2���� ��ȿ�� Ÿ���϶��� �κ� ����ȭ
template<typename A, typename B>
class xtuple<A, B, NullType, NummType, NullType> : public(�θ�)
int main()
{
	//					Duo<long, double>
	//				Duo<short, xtuple<long,double,N,N,N>>
	//		   Duo<char,long,double>
	//Duo<int, xtuple<char, short, long, double, N>>
	xtuple<int, char, short, long, double>t5;
	xtuple<int, int, int> t3;
}