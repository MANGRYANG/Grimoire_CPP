/*

	Const Keyword 사용 예시

*/

#include <iostream>

int main(void)
{
	// const 키워드를 사용한 변수의 상수화

	// 일반 변수 선언
	char a = 'A';
	char b = 'B';
	char c = 'C';

	// const 키워드를 사용하여 상수화된 변수 선언
	const char d = 'D';

	a = 'a'; // 일반 변수는 값 변경 가능
	// d = 'd'; // const 변수는 값 변경 불가능하여 주석 처리


	// const 키워드를 사용한 포인터의 상수화

	char* ptr_a = &a; // 일반 포인터 선언
	*ptr_a = 'A'; // 포인터가 가리키는 값 변경 가능

	std::cout << *ptr_a << std::endl; // a의 값인 'A'가 출력됨


	const char* ptr_b = &b; // const 포인터 선언
	// *ptr_b = 'b'; // 포인터 변수가 가리키는 값을 변경할 수 없으므로 주석 처리
	ptr_b = &c; // 포인터 변수 자체는 다른 주소를 가리킬 수 있음

	std::cout << *ptr_b << std::endl; // c의 값인 'C'가 출력됨


	char* const ptr_c = &c; // const 포인터 선언
	*ptr_c = 'c'; // 포인터가 가리키는 값은 변경 가능
	// ptr_c = &b; // 상수화된 변수인 ptr_c는 다른 주소를 가리킬 수 없으므로 주석 처리

	std::cout << *ptr_c << std::endl; // c의 값인 'c'가 출력됨

	return 0;
}