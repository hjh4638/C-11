#include <iostream>
using namespace std;

// C++ Programming Language 책 13장에 아래 예제의 전체 코드가 있습니다.
// 얀 Stroustup
class String
{
	char* buf;
	int* ref; // 참조 계수
public:
	String(char const* s)
	{
		buf = new char[strlen(s) + 1];
		strcpy(buf, s);
		ref = new int(1);
	}
	String(String const& s)
	{
		buf = s.buf;
		ref = s.ref;
		++(*ref);
	}
	~String()
	{
		if (--(*ref) == 0)
		{
			delete[] buf;
			delete ref;
		}
	}

	// 문제를 해결하기 위해 새로운 요소를 도입한다.
	// char 를 대신하는 요소를 만들자
	class CharProxy
	{
		String& str;
		int index;
	public:
		CharProxy(String& s, int n) : str(s), index(n){}

		// Proxy 는 char로 변할 수 있어야 한다.
		operator char()
		{
			cout << "읽는 작업중. 복사본 필요 없다" << endl;
			return str.buf[index];
		}
		// Proxy는 char를 대입할 수 있어야 한다.
		CharProxy& operator=(char c)
		{
			cout << "쓰는 작업중. 복사본을 만들어야 한다" << endl;
			
			// 버퍼 복사본
			char* temp = new char[strlen(str.buf) + 1];
			strcpy(temp, str.buf);

			if (--(*str.ref) == 0)
			{
				delete[] str.buf;
				delete str.ref;
			}
			str.buf = temp;
			str.ref = new int(1);

			str.buf[index] = c;
			return *this;
		}
	};
	CharProxy operator[](int n)
	{
		cout << "operator[]" << endl;
		return CharProxy(*this, n);
	}
	/*
	// [] 연산자 재정의 : 객체를 배열처럼 사용가능하게 한다.
	// s[0] = 'a' 처럼 [] 호출이 lvalue에 오게 하려면
	// 참조 리턴해야 한다.
	char& operator[](int n)
	{
		cout << "operator[]" << endl;
		return buf[n]; 
	}
	*/
	void print() const { cout << buf << endl; }
};

int main()
{
	String s1 = "hello";
	String s2 = s1; //잘 생각해보세요.

	char c = s1[0]; // 읽는 작업이다. 자원(문자열)은 계속 공유되어야
					//한다.
	cout << c << endl; // 'h'

	s1[0] = 'x'; // 쓰는 작업이다. 자원을 분리하고 변경해야한다
				 // Copy On Write

	s1.print(); // "xello"
	s2.print(); // "hello"
}