/*

	동적 메모리 할당 예시 코드

*/

#include <iostream>

int main(void)
{
	// 동적 메모리 할당
	int* ptr_i = new int;

	// 동적 메모리에 값 할당
	*ptr_i = 42;

	// 동적 메모리에서 값 출력
	std::cout << *ptr_i << std::endl;

	// 동적 메모리 해제
	delete ptr_i;

	std::cout << std::endl;

	// 배열 동적 메모리 할당
	int* ptr_arr = new int[5];

	// 배열 동적 메모리에 값 할당
	for (int i = 0; i < 5; ++i)
	{
		ptr_arr[i] = i + 1; // 1부터 5까지의 값 할당
	}

	// 배열 동적 메모리에서 값 출력
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Element " << i << ": " << ptr_arr[i] << std::endl;
	}

	// 배열 동적 메모리 해제
	delete[] ptr_arr;

	return 0;
}