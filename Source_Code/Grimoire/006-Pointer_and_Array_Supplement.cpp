/*

	배열에서의 포인터 사용 예시 코드 - 보충

*/

#include <iostream>

int main(void)
{
	// 배열 선언
	int arr[] = { 1, 2, 3, 4, 5 };

	// 배열의 첫 번째 요소를 가리키는 포인터 선언
	int* ptr = arr;

	// 포인터를 사용하여 배열 요소 출력
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "Element " << i << ": " << *(ptr + i) << std::endl;
	}

	std::cout << sizeof(ptr) << " bytes" << std::endl;	// int* 포인터의 크기인 8 bytes가 출력된다.

	std::cout << std::endl;

	// 배열명을 직접 포인터로 사용하여 배열 요소 출력
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "Element " << i << ": " << *(arr + i) << std::endl;
	}

	std::cout << sizeof(arr) << " bytes" << std::endl;	// int 배열의 크기인 20 bytes가 출력된다. (5 * sizeof(int) = 5 * 4 = 20)

	return 0;
}