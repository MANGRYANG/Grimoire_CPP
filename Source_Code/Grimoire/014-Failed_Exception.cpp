/*

	Exception 실패 상황 처리 예시 코드

*/

#include <iostream>
#include <cstdlib>	// abort() 함수 사용을 위한 헤더 파일

// 사용자 정의 terminate 함수 정의
static void customTerminate()
{
	std::cout << "terminate() called" << std::endl;
	// 프로그램 비정상 종료
	std::abort();
}

int main(void)
{
	set_terminate(customTerminate); // 종료 처리 함수를 customTerminate()으로 설정

	throw "Exception"; // 예외 발생

	// catch 블록이 없어 예외가 처리되지 못해 종료 처리 함수가 호출된다.

	return 0;
}