/*

	C++ �ڵ忡���� ���̻� ��� ���� �ڵ�

*/

#include <iostream>

// ���̻� ��ǥ�� ���� �ڵ带 ���� �Լ� �����ε�
// float Ÿ���� �޴� �Լ�
static void func(float x)
{
	std::cout << x << " - float version\n";
}

// double Ÿ���� �޴� �Լ�
static void func(double x)
{
	std::cout << x << " - double version\n";
}

int main(void)
{
	// unsigned int Ÿ�� ���� ����
	unsigned int uNumber_A = 42u; // �ҹ��� u ���
	unsigned int uNumber_B = 42U; // �빮�� U�� ��� ����

	// long Ÿ�� ���� ����
	long longNumber_A = 1234567890l; // �ҹ��� l ���
	long longNumber_B = 1234567890L; // �빮�� L�� ��� ����

	// unsigned long Ÿ�� ���� ����
	unsigned long ulongNumber_A = 1234567890ul; // �ҹ��� ul ���
	unsigned long ulongNumber_B = 1234567890UL; // �빮�� UL�� ��� ����

	// long long Ÿ�� ���� ����
	long long longLongNumber_A = 1234567890123456789ll; // �ҹ��� ll ���
	long long longLongNumber_B = 1234567890123456789LL; // �빮�� LL�� ��� ����

	// unsigned long long Ÿ�� ���� ����
	unsigned long long ulongLongNumber_A = 12345678901234567890ull; // �ҹ��� ull ���
	unsigned long long ulongLongNumber_B = 12345678901234567890ULL; // �빮�� ULL�� ��� ����

	// float Ÿ�� ���� ����
	float floatNumber_A = 3.14f; // �ҹ��� f ���
	float floatNumber_B = 3.14F; // �빮�� F�� ��� ����

	// long double Ÿ�� ���� ����
	long double longDoubleNumber_A = 3.14l; // �ҹ��� l ��� (long Ÿ�԰� ����)
	long double longDoubleNumber_B = 3.14L; // �빮�� L�� ��� ����

	// ���̻� ��ǥ�� �ڵ� ����
	func(3.14f); // ���̻� f�� ����Ͽ� float Ÿ������ �ν�
	func(3.14); // ���̻� f�� ������� �ʾ� �⺻ Ÿ���� double Ÿ������ �ν�

	return 0;
}