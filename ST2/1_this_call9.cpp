#include <iostream>
using namespace std;

//callback�� �Լ� ������ ����
class Button{
	//void(*handler)();
	void(T::*handler)();
	Dialog* pDlg;
public:
	void setHandler(void(*f)()){
		handler = f;
	}
	void click(){
		//��ư�� ���ȴٴ� ����� �ܺο� �����մϴ�.
		//���� "��ü�� �ܺο� �̺�Ʈ�� �߻��Ѵ�."��� ǥ��!
		handler();
	}
};
//-----------
void btn1Handler(){ cout << "��ư 1 Ŭ��" << endl; }
int main(){
	Button b1, b2;
	b1.setHandler(&btn1Handler); 
	b1.click();// ����ڰ� ��ư�� Ŭ���ϸ� ���Լ��� ȣ��ȴٰ� �����մϴ�.
}