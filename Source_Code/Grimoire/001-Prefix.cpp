/*

	C++ 코드에서의 접두사 사용 예시 코드

*/

#include <iostream>
	// string 라이브러리가 포함되어 있음

// WideCharToMultiByte 함수 사용을 위한 헤더 파일
#include <windows.h>

int main(void)
{
	// 선언부

	// 일반 문자열 선언
	std::string NormalString("This is normal string!");

	// w_char 문자열 선언 (접두사 L 사용)
	std::wstring WideString(L"This is wide string!");

	// UTF-8 문자열 선언 (접두사 u8 사용)
	std::u8string UTF8String(u8"This is UTF-8 string!");

	// UTF-16 문자열 선언 (접두사 u 사용)
	std::u16string UTF16String(u"This is UTF-16 string!");


	// 출력부

	// 일반적인 출력 형식
	std::cout << NormalString << std::endl;

	// wcout을 사용하여 wide string 출력
	std::wcout << WideString << std::endl;

	// UTF-8 문자열 출력
	/*

		std::ostream& operator<<(std::ostream & os, const std::u8string & str); 는 정의되어 있지 않으므로,
		std::u8string을 c_str() 함수를 통해 const char8_t*로 변환한 뒤 const char*으로 캐스팅하여 출력해야 한다.

		이 때 reinterpret_cast를 사용하여 cosnt char8_t*를 const char*로 변환한다.
		reinterpret_cast는 타입 변환을 강제로 수행하여 보통 위험하나 이 경우에는 같은 내부 비트 패턴을 가지므로 안전하다.

	*/
	std::cout << reinterpret_cast<const char*>(UTF8String.c_str()) << std::endl;

	// UTF-16 문자열 출력
	// UTF_16 문자열을 UTF-8로 변환하는 람다 함수 정의 (std::string 형태의 문자열으로 반환)
	auto utf16ToUtf8 = [](const std::u16string& UTF16String) -> std::string
		{
		// UTF-16 문자열이 비어있으면 빈 문자열 반환
		if (UTF16String.empty()) return {};

		// UTF-16 문자열의 길이를 통해 변환 시 필요한 버퍼의 크기 계산 (실제 변환 수행하지 않음)
		int sizeNeeded = WideCharToMultiByte(
			CP_UTF8, 0,
			reinterpret_cast<LPCWCH>(UTF16String.c_str()),
			static_cast<int>(UTF16String.size()),
			nullptr, 0, nullptr, nullptr
		);

		// 반환할 문자열 선언
		std::string utf8Str(sizeNeeded, 0);
		// UTF-16 문자열을 UTF-8 문자열로 변환
		WideCharToMultiByte(
			CP_UTF8, 0,
			reinterpret_cast<LPCWCH>(UTF16String.c_str()),
			static_cast<int>(UTF16String.size()),
			utf8Str.data(), sizeNeeded, nullptr, nullptr
		);

		// 변환된 UTF-8 문자열 반환
		return utf8Str;
		};

	// UTF-16 문자열을 UTF-8로 변환하여 출력
	std::cout << utf16ToUtf8(UTF16String) << std::endl;

	return 0;
}