/*

	Exception 처리 예시 코드

*/

#include <iostream>

// 함수 전방 선언
static void func1();
static void func2();
static void funcException();

static void func1()
{
	// func1 함수가 호출되었음을 알리는 메시지 출력
	std::cout << "func1() called" << std::endl;

	func2(); // func2 함수 호출

	// func1 함수가 끝났음을 알리는 메시지 출력
	std::cout << "func1() finished" << std::endl;	// 출력되지 않음!
}

static void func2()
{
	// func2 함수가 호출되었음을 알리는 메시지 출력
	std::cout << "func2() called" << std::endl;
	
	funcException(); // funcException 함수 호출

	// func2 함수가 끝났음을 알리는 메시지 출력
	std::cout << "func2() finished" << std::endl;	// 출력되지 않음!
}

static void funcException()
{
	// funcException 함수가 호출되었음을 알리는 메시지 출력
	std::cout << "funcException() called" << std::endl;

	// 예외 발생
	throw "funcException"; // 예외를 발생시키는 코드
	
	// funcException 함수가 끝났음을 알리는 메시지 출력
	std::cout << "funcException() finished" << std::endl;	// 출력되지 않음!
}

int main(void)
{
	try
	{
		func1(); // func1 함수 호출
	}
	catch (const char* e)	// 문자열 예외 처리
	{
		// 문자열 예외가 발생했을 때 실행되는 코드
		std::cout << "Caught exception: " << e << std::endl; // 문자열 예외 메시지 출력
	}
	catch (...)	 // 앞서 선언된 예외들을 제외한 모든 예외 처리
	{
		// 모든 예외를 처리하는 코드
		std::cout << "Caught unknown exception" << std::endl; // 알 수 없는 예외 메시지 출력
	}

	return 0;
}