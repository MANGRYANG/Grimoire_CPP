/*

	Call by Value, Call by Reference, Call by Address�� ��� ���� �ڵ�

*/

#include <iostream>

// Call by Value
static void Swap_CBV(int a, int b)
{
	// ���� ����Ǿ� ���޵ǹǷ�, ���� ���� ��ȯ���� �ʴ´�.
	int temp = a;
	a = b;
	b = temp;
}

// Call by Reference
static void Swap_CBR(int& a, int& b)
{
	// ������ ���޵ǹǷ�, ���� ���� ��ȯ�ȴ�.
	int temp = a;
	a = b;
	b = temp;
}

// Call by Address
static void Swap_CBA(int* a, int* b)
{
	// �ּҸ� ���� �����ϹǷ�, ���� ���� ��ȯ�ȴ�.
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	// ���� ����
	int x, y;

	// ���� �� �ʱ�ȭ
	x = 10;
	y = 20;

	// Call by Value
	Swap_CBV(x, y);
	// ��� ���
	std::cout << "Call by Value: a = " << x << ", b = " << y << '\n' << std::endl;

	// ���� �� �ʱ�ȭ
	x = 10;
	y = 20;

	// Call by Reference
	Swap_CBR(x, y);
	// ��� ���
	std::cout << "Call by Reference: a = " << x << ", b = " << y << '\n' << std::endl;
	
	// ���� �� �ʱ�ȭ
	x = 10;
	y = 20;

	// Call by Address
	Swap_CBA(&x, &y);
	// ��� ���
	std::cout << "Call by Address: a = " << x << ", b = " << y << '\n' << std::endl;

	return 0;
}