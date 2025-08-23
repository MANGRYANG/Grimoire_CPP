/*

	Exception ���� ��Ȳ ó�� ���� �ڵ�

*/

#include <iostream>
#include <cstdlib>	// abort() �Լ� ����� ���� ��� ����

// ����� ���� terminate �Լ� ����
static void customTerminate()
{
	std::cout << "terminate() called" << std::endl;
	// ���α׷� ������ ����
	std::abort();
}

int main(void)
{
	set_terminate(customTerminate); // ���� ó�� �Լ��� customTerminate()���� ����

	throw "Exception"; // ���� �߻�

	// catch ����� ���� ���ܰ� ó������ ���� ���� ó�� �Լ��� ȣ��ȴ�.

	return 0;
}