/*

	Assertion을 이용한 예외처리 예시 코드

*/

#include <iostream>
#include <cassert>	// Assertion 사용을 위한 헤더 파일

int main(void)
{
	int x = 10;
	int y = 2;

	// y = 0; // y를 0으로 설정하여 나누기 예외를 발생시는 코드 - 주석처리함

	// Assertion을 사용하여 y가 0이 아닌지 확인
	assert(y != 0); // y가 0이면 프로그램이 중단되고 메시지가 출력됨

	std::cout << "x / y = " << (x / y) << std::endl;

	return 0;
}