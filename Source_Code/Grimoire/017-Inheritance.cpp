/*

	��� ���� ������ ���� �ڵ�

*/

#include <iostream>

// �θ� Ŭ����
class Parent
{
	// Private ��� ���� �� �Լ��� �ڽ� Ŭ�������� ������ �� ���� ������ �ۼ����� ����
private:
	// Protected ��� ���� �� �Լ�
protected:
	int protected_member_p = 0;  // protected ��� ����
	void protected_function_p()  // protected ��� �Լ�
	{
		std::cout << "Protected Function\n";
	}
	// public ��� ���� �� �Լ�
public:
	int public_member_p = 0;  // public ��� ����
	void public_function_p()  // public ��� �Լ�
	{
		std::cout << "Public Function\n";
	}
};

// public���� �θ� Ŭ���� ���
class Child_public : public Parent
{
};

// protected�� �θ� Ŭ���� ���
class Child_protected : protected Parent
{
};

// private���� �θ� Ŭ���� ���
class Child_private : private Parent
{
};

// �θ� Ŭ������ ������ �Ű������� �޴� �Լ� ����
void func(Parent&);

int main(void)
{
	// �θ� Ŭ���� ��ü ����
	Parent parent;
	// �ڽ� Ŭ���� ��ü ����
	Child_public child_public;
	Child_protected child_protected;
	Child_private child_private;

	// �θ� Ŭ������ ��ü�� �Ű������� ����
	func(parent);

	// public���� ��ӹ��� �ڽ� Ŭ������ ��ü�� �Ű������� ����
	func(child_public);

	// protected�� ��ӹ��� �ڽ� Ŭ������ ��ü�� �Ű������� ����
	// 
	// func(child_protected);
	
	// private�� ��ӹ��� �ڽ� Ŭ������ ��ü�� �Ű������� ����
	// private ���� �����ڸ� ���� ��ӹ��� ��� �ڽ� Ŭ���� ��ü�� �θ� Ŭ���� Ÿ������ ��ȯ�� �� ����
	// func(child_private);

	// public ���� �����ڸ� ���� ��ӹ��� ���
	// 
	// �θ� Ŭ������ protected ����� protected���� ��޵Ǿ� �ܺο��� ������ �� ����
	/*
	child_public.protected_member_p = 10;
	child_public.protected_function_p();
	*/
	// 
	// �θ� Ŭ������ public ����� public���� ��޵Ǿ� �ܺο��� ������ �� ����
	child_public.public_member_p = 20;
	child_public.public_function_p();

	// protected ���� �����ڸ� ���� ��ӹ��� ���
	// 
	// �θ� Ŭ������ protected ����� protected���� ��޵Ǿ� �ܺο��� ������ �� ����
	/*
	child_protected.protected_member_p = 10;
	child_protected.protected_function_p();
	*/
	//
	// �θ� Ŭ������ public ����� protected���� ��޵Ǿ� �ܺο��� ������ �� ����
	/*
	child_protected.public_member_p = 20;
	child_protected.public_function_p();
	*/

	// private ���� �����ڸ� ���� ��ӹ��� ���
	// 
	// �θ� Ŭ������ protected ����� private���� ��޵Ǿ� �ܺο��� ������ �� ����
	/*
	child_private.protected_member_p = 10;  // private ������� ���� ���� �Ұ�
	child_private.protected_function_p();  // private ������� ���� ���� �Ұ�
	*/
	//
	// �θ� Ŭ������ public ����� private���� ��޵Ǿ� �ܺο��� ������ �� ����
	/*
	child_private.public_member_p = 20;  // private ������� ���� ���� �Ұ�
	child_private.public_function_p();  // private ������� ���� ���� �Ұ�
	*/

	return 0;
}