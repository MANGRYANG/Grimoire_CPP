/*

	Call by Value, Call by Reference, Call by Address의 사용 예시 코드

*/

#include <iostream>

// Call by Value
static void Swap_CBV(int a, int b)
{
	// 값이 복사되어 전달되므로, 원본 값은 교환되지 않는다.
	int temp = a;
	a = b;
	b = temp;
}

// Call by Reference
static void Swap_CBR(int& a, int& b)
{
	// 참조가 전달되므로, 원본 값이 교환된다.
	int temp = a;
	a = b;
	b = temp;
}

// Call by Address
static void Swap_CBA(int* a, int* b)
{
	// 주소를 통해 접근하므로, 원본 값이 교환된다.
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	// 변수 선언
	int x, y;

	// 원본 값 초기화
	x = 10;
	y = 20;

	// Call by Value
	Swap_CBV(x, y);
	// 결과 출력
	std::cout << "Call by Value: a = " << x << ", b = " << y << '\n' << std::endl;

	// 원본 값 초기화
	x = 10;
	y = 20;

	// Call by Reference
	Swap_CBR(x, y);
	// 결과 출력
	std::cout << "Call by Reference: a = " << x << ", b = " << y << '\n' << std::endl;
	
	// 원본 값 초기화
	x = 10;
	y = 20;

	// Call by Address
	Swap_CBA(&x, &y);
	// 결과 출력
	std::cout << "Call by Address: a = " << x << ", b = " << y << '\n' << std::endl;

	return 0;
}