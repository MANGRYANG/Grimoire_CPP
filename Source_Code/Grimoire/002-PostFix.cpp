/*

	C++ 코드에서의 접미사 사용 예시 코드

*/

#include <iostream>

// 접미사 미표기 예시 코드를 위한 함수 오버로딩
// float 타입을 받는 함수
static void func(float x)
{
	std::cout << x << " - float version\n";
}

// double 타입을 받는 함수
static void func(double x)
{
	std::cout << x << " - double version\n";
}

int main(void)
{
	// unsigned int 타입 변수 선언
	unsigned int uNumber_A = 42u; // 소문자 u 사용
	unsigned int uNumber_B = 42U; // 대문자 U도 사용 가능

	// long 타입 변수 선언
	long longNumber_A = 1234567890l; // 소문자 l 사용
	long longNumber_B = 1234567890L; // 대문자 L도 사용 가능

	// unsigned long 타입 변수 선언
	unsigned long ulongNumber_A = 1234567890ul; // 소문자 ul 사용
	unsigned long ulongNumber_B = 1234567890UL; // 대문자 UL도 사용 가능

	// long long 타입 변수 선언
	long long longLongNumber_A = 1234567890123456789ll; // 소문자 ll 사용
	long long longLongNumber_B = 1234567890123456789LL; // 대문자 LL도 사용 가능

	// unsigned long long 타입 변수 선언
	unsigned long long ulongLongNumber_A = 12345678901234567890ull; // 소문자 ull 사용
	unsigned long long ulongLongNumber_B = 12345678901234567890ULL; // 대문자 ULL도 사용 가능

	// float 타입 변수 선언
	float floatNumber_A = 3.14f; // 소문자 f 사용
	float floatNumber_B = 3.14F; // 대문자 F도 사용 가능

	// long double 타입 변수 선언
	long double longDoubleNumber_A = 3.14l; // 소문자 l 사용 (long 타입과 동일)
	long double longDoubleNumber_B = 3.14L; // 대문자 L도 사용 가능

	// 접미사 미표기 코드 예시
	func(3.14f); // 접미사 f를 사용하여 float 타입으로 인식
	func(3.14); // 접미사 f를 사용하지 않아 기본 타입인 double 타입으로 인식

	return 0;
}