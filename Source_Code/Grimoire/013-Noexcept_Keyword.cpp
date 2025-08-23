/*

	Noexcept Keyword ��� ����

*/

#include <iostream>

// noexcept Ű���带 ����Ͽ� �Լ��� ���ܸ� �߻���Ű�� ������ ��������� ǥ��
static void noexceptFunction1() noexcept
{
	// �� �Լ��� ���ܸ� �߻���Ű�� ������ �˸��� �޽��� ���
	std::cout << "This function will not throw an exception." << std::endl;
}

// noexcept Ű���带 ����Ͽ����� �����δ� ���ܸ� �߻���Ű�� �Լ�
static void noexceptFunction2() noexcept
{
	// �� �Լ��� ���ܸ� �߻���Ű�� ������ �˸��� �޽��� ���
	std::cout << "This function will not throw an exception(?)." << std::endl;

	throw "An exception occurred"; // ���ܸ� �߻���Ű�� �ڵ�
}

int main(void)
{
	// ������ Ÿ�ӿ� noexcept ���θ� Ȯ���ϹǷ�, �Լ��� ������ ȣ������� �ʴ´�.
	std::cout << noexcept(noexceptFunction1()) << std::endl;	// noexcept�� �����Ǿ����Ƿ� true(1) ���
	std::cout << noexcept(noexceptFunction2()) << std::endl;	// noexcept�� �����Ǿ����Ƿ� true(1) ���

	noexceptFunction1(); // noexceptFunction1 ȣ��

	try
	{
		noexceptFunction2(); // noexceptFunction2 ȣ��
		// ���ܰ� �߻������� noexcept�� �����Ǿ� �ֱ� ������ std::terminate()�� ȣ��Ǿ� ���α׷��� ������ ������ ����ȴ�.
	}
	// ���� catch ����� ������� ����.
	catch (const char* e) // ���ڿ� ���� ó��
	{
		// ���ܰ� �߻����� �� ����Ǵ� �ڵ�
		std::cout << "Caught exception: " << e << std::endl; // ���� �޽��� ���
	}
	catch (...) // ��� ���� ó��
	{
		std::cout << "Caught an unknown exception." << std::endl;

	}
	return 0;
}