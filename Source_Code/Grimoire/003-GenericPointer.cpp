/*

	Generic Pointer 사용 예시 코드

	Generic Pointer : void* 타입의 포인터로, 어떤 타입의 변수도 가리킬 수 있는 포인터를 의미한다.
	다양한 타입의 변수를 처리할 수 있으며 타입에 따라 적절한 캐스팅을 수행하여 사용한다.

*/

#include <iostream>

int main(void)
{
	int int_value = 42; // 정수형 변수 선언
	double double_value = 3.14; // 실수형 변수 선언

	// Generic Pointer 선언
	void* generic_pointer;

	// 정수형 변수의 주소를 Generic Pointer에 저장
	generic_pointer = &int_value;
	// Generic Pointer를 int*로 캐스팅하여 포인터가 가리키는 값 출력
	std::cout << *static_cast<int*>(generic_pointer) << std::endl;

	// 실수형 변수의 주소를 Generic Pointer에 저장
	generic_pointer = &double_value;
	// Generic Pointer를 double*로 캐스팅하여 포인터가 가리키는 값 출력
	std::cout << *static_cast<double*>(generic_pointer) << std::endl;

	return 0;
}