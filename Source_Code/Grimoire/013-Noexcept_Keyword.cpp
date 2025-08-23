/*

	Noexcept Keyword 사용 예시

*/

#include <iostream>

// noexcept 키워드를 사용하여 함수가 예외를 발생시키지 않음을 명시적으로 표시
static void noexceptFunction1() noexcept
{
	// 이 함수는 예외를 발생시키지 않음을 알리는 메시지 출력
	std::cout << "This function will not throw an exception." << std::endl;
}

// noexcept 키워드를 사용하였으나 실제로는 예외를 발생시키는 함수
static void noexceptFunction2() noexcept
{
	// 이 함수는 예외를 발생시키지 않음을 알리는 메시지 출력
	std::cout << "This function will not throw an exception(?)." << std::endl;

	throw "An exception occurred"; // 예외를 발생시키는 코드
}

int main(void)
{
	// 컴파일 타임에 noexcept 여부를 확인하므로, 함수가 실제로 호출되지는 않는다.
	std::cout << noexcept(noexceptFunction1()) << std::endl;	// noexcept로 설정되었으므로 true(1) 출력
	std::cout << noexcept(noexceptFunction2()) << std::endl;	// noexcept로 설정되었으므로 true(1) 출력

	noexceptFunction1(); // noexceptFunction1 호출

	try
	{
		noexceptFunction2(); // noexceptFunction2 호출
		// 예외가 발생하지만 noexcept로 설정되어 있기 때문에 std::terminate()가 호출되어 프로그램이 강제로 비정상 종료된다.
	}
	// 이후 catch 블록은 실행되지 않음.
	catch (const char* e) // 문자열 예외 처리
	{
		// 예외가 발생했을 때 실행되는 코드
		std::cout << "Caught exception: " << e << std::endl; // 예외 메시지 출력
	}
	catch (...) // 모든 예외 처리
	{
		std::cout << "Caught an unknown exception." << std::endl;

	}
	return 0;
}