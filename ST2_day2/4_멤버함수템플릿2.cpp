class Animal{};
class Dog :public Animal{};

int main()
{
	Dog* p1 = new Dog;
	Animal* p2 = p1; //�θ� Ÿ�� �����ʹ� �ڽ��� �ּҸ� ���� �� 
					 //�ֽ��ϴ�.
	//������ ������ ��� ����Ʈ �����͸� ���� ����մϴ�(���� ���)

	//sp : �ȵ���̵� �����ӿ�ũ�� �ִ� ����Ʈ ������
	sp<Dog> p1 = new Dog;
	sp<Animal> p2 = p1;

	p2 = p1;
	if (p2 == p1){}
	//����Ʈ�����Ϳ��� �ݵ�� ����/����/==/!= �� template ��������
	//�־�� �մϴ�
}

//cafe.naver.com/cppmaster���� ���� ���� �ڷ�ǿ��� kitkat �˻��غ�����.
//core/include/utils/strongpointer.h