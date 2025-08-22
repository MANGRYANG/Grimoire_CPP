/*

	사용자 지정 리터럴 예시 코드

	return_type operator"" literal_name (parameter) <- 해당 문법을 통해 사용자 지정 리터럴을 사용할 수 있다.
*/

#include <iostream>

static unsigned long long operator"" _ByteToBit(unsigned long long x)
{
	return x * 8; // 바이트 -> 비트
}

static unsigned long long operator"" _KibibyteToBit(unsigned long long x)
{
	return x * 1024 * 8; // 키비바이트 -> 비트
}

static unsigned long long operator"" _MebibyteToBit(unsigned long long x)
{
	return x * 1024 * 1024 * 8; // 메비바이트 -> 비트
}

static unsigned long long operator"" _GibibyteToBit(unsigned long long x)
{
	return x * 1024 * 1024 * 1024 * 8; // 기비바이트 -> 비트
}

int main(void)
{
	// 사용자 지정 리터럴 사용 예시
	std::cout << "1 Byte == " << 1_ByteToBit << " Bit" << std::endl;
	std::cout << "1 Kibibyte == " << 1_KibibyteToBit << " Bit" << std::endl;
	std::cout << "1 Mebibyte == " << 1_MebibyteToBit << " Bit" << std::endl;
	std::cout << "1 Gibibyte == " << 1_GibibyteToBit << " Bit" << std::endl;

	return 0;
}