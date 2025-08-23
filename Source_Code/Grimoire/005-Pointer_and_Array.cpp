/*

	배열에서의 포인터 사용 예시 코드

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

	std::cout << std::endl;

	// 배열명을 직접 포인터로 사용하여 배열 요소 출력
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "Element " << i << ": " << *(arr + i) << std::endl;
	}

	return 0;
}