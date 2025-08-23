/*

	Exception ó�� ���� �ڵ�

*/

#include <iostream>

// �Լ� ���� ����
static void func1();
static void func2();
static void funcException();

static void func1()
{
	// func1 �Լ��� ȣ��Ǿ����� �˸��� �޽��� ���
	std::cout << "func1() called" << std::endl;

	func2(); // func2 �Լ� ȣ��

	// func1 �Լ��� �������� �˸��� �޽��� ���
	std::cout << "func1() finished" << std::endl;	// ��µ��� ����!
}

static void func2()
{
	// func2 �Լ��� ȣ��Ǿ����� �˸��� �޽��� ���
	std::cout << "func2() called" << std::endl;
	
	funcException(); // funcException �Լ� ȣ��

	// func2 �Լ��� �������� �˸��� �޽��� ���
	std::cout << "func2() finished" << std::endl;	// ��µ��� ����!
}

static void funcException()
{
	// funcException �Լ��� ȣ��Ǿ����� �˸��� �޽��� ���
	std::cout << "funcException() called" << std::endl;

	// ���� �߻�
	throw "funcException"; // ���ܸ� �߻���Ű�� �ڵ�
	
	// funcException �Լ��� �������� �˸��� �޽��� ���
	std::cout << "funcException() finished" << std::endl;	// ��µ��� ����!
}

int main(void)
{
	try
	{
		func1(); // func1 �Լ� ȣ��
	}
	catch (const char* e)	// ���ڿ� ���� ó��
	{
		// ���ڿ� ���ܰ� �߻����� �� ����Ǵ� �ڵ�
		std::cout << "Caught exception: " << e << std::endl; // ���ڿ� ���� �޽��� ���
	}
	catch (...)	 // �ռ� ����� ���ܵ��� ������ ��� ���� ó��
	{
		// ��� ���ܸ� ó���ϴ� �ڵ�
		std::cout << "Caught unknown exception" << std::endl; // �� �� ���� ���� �޽��� ���
	}

	return 0;
}