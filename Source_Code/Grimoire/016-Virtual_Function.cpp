/*

	Virtual Function ���� �ڵ�

*/

#include <iostream>

// �θ� Ŭ����
class Parent
{
public:
    void foo()  // �Ϲ� ��� �Լ� ����
    {
        std::cout << "Parent\n";
    }

    virtual void foo_virtual()  // virtual Ű���带 ����Ͽ� ���� ��� �Լ� ����
    {
        std::cout << "Parent-Virtual\n";
    }
};

// �ڽ� Ŭ����
class Child : public Parent
{
public:
	void foo()  // �θ� Ŭ������ �Ϲ� �Լ��� ���� �̸����� ����
    {
        std::cout << "Child\n";
    }

	void foo_virtual() override // �θ� Ŭ������ virtual �Լ��� �������̵�
	{
		std::cout << "Child-Virtual\n";
	}
};

int main(void)
{
    // �θ� Ÿ�� �����͸� �����ϰ� �ڽ� Ŭ������ ��ü�� �����Ͽ� �Ҵ� : ��ĳ����
    Parent* p = new Child();

    // foo()�� virtual�� �ƴϹǷ� ���� ���ε��� �߻���
    // ���� ���ε� : ������ Ÿ�ӿ� � �Լ��� ȣ��� �� �����Ǵ� ���
    // ������ ������ Parent::foo ȣ��� ������
    // Child::foo�� �Լ� ����(name hiding)���� ���� ȣ����� ����
    p->foo();  // Parent::foo ȣ��
    
    // foo_virtual()�� virtual�̹Ƿ� ���� ���ε� �߻�
    // ���� ���ε�: ���� �ð��� ���� ��ü Ÿ���� ���� ȣ���� �Լ� ����
    // p�� Child ��ü�� ����Ű�Ƿ� Child::foo_virtual�� ȣ���
	p->foo_virtual();  // Child::foo_virtual ȣ�� 
}