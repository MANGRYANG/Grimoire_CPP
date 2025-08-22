/*

	����� ���� ���ͷ� ���� �ڵ�

	return_type operator"" literal_name (parameter) <- �ش� ������ ���� ����� ���� ���ͷ��� ����� �� �ִ�.
*/

#include <iostream>

static unsigned long long operator"" _ByteToBit(unsigned long long x)
{
	return x * 8; // ����Ʈ -> ��Ʈ
}

static unsigned long long operator"" _KibibyteToBit(unsigned long long x)
{
	return x * 1024 * 8; // Ű�����Ʈ -> ��Ʈ
}

static unsigned long long operator"" _MebibyteToBit(unsigned long long x)
{
	return x * 1024 * 1024 * 8; // �޺����Ʈ -> ��Ʈ
}

static unsigned long long operator"" _GibibyteToBit(unsigned long long x)
{
	return x * 1024 * 1024 * 1024 * 8; // ������Ʈ -> ��Ʈ
}

int main(void)
{
	// ����� ���� ���ͷ� ��� ����
	std::cout << "1 Byte == " << 1_ByteToBit << " Bit" << std::endl;
	std::cout << "1 Kibibyte == " << 1_KibibyteToBit << " Bit" << std::endl;
	std::cout << "1 Mebibyte == " << 1_MebibyteToBit << " Bit" << std::endl;
	std::cout << "1 Gibibyte == " << 1_GibibyteToBit << " Bit" << std::endl;

	return 0;
}