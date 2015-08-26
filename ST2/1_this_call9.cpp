#include <iostream>
using namespace std;

//callback과 함수 포인터 문제
class Button{
	//void(*handler)();
	void(T::*handler)();
	Dialog* pDlg;
public:
	void setHandler(void(*f)()){
		handler = f;
	}
	void click(){
		//버튼이 눌렸다는 사실을 외부에 전달합니다.
		//흔히 "객체가 외부에 이벤트를 발생한다."라고 표현!
		handler();
	}
};
//-----------
void btn1Handler(){ cout << "버튼 1 클릭" << endl; }
int main(){
	Button b1, b2;
	b1.setHandler(&btn1Handler); 
	b1.click();// 사용자가 버튼을 클릭하면 이함수가 호출된다고 가정합니다.
}