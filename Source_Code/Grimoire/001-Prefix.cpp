/*

	C++ �ڵ忡���� ���λ� ��� ���� �ڵ�

*/

#include <iostream>
	// string ���̺귯���� ���ԵǾ� ����

// WideCharToMultiByte �Լ� ����� ���� ��� ����
#include <windows.h>

int main(void)
{
	// �����

	// �Ϲ� ���ڿ� ����
	std::string NormalString("This is normal string!");

	// w_char ���ڿ� ���� (���λ� L ���)
	std::wstring WideString(L"This is wide string!");

	// UTF-8 ���ڿ� ���� (���λ� u8 ���)
	std::u8string UTF8String(u8"This is UTF-8 string!");

	// UTF-16 ���ڿ� ���� (���λ� u ���)
	std::u16string UTF16String(u"This is UTF-16 string!");


	// ��º�

	// �Ϲ����� ��� ����
	std::cout << NormalString << std::endl;

	// wcout�� ����Ͽ� wide string ���
	std::wcout << WideString << std::endl;

	// UTF-8 ���ڿ� ���
	/*

		std::ostream& operator<<(std::ostream & os, const std::u8string & str); �� ���ǵǾ� ���� �����Ƿ�,
		std::u8string�� c_str() �Լ��� ���� const char8_t*�� ��ȯ�� �� const char*���� ĳ�����Ͽ� ����ؾ� �Ѵ�.

		�� �� reinterpret_cast�� ����Ͽ� cosnt char8_t*�� const char*�� ��ȯ�Ѵ�.
		reinterpret_cast�� Ÿ�� ��ȯ�� ������ �����Ͽ� ���� �����ϳ� �� ��쿡�� ���� ���� ��Ʈ ������ �����Ƿ� �����ϴ�.

	*/
	std::cout << reinterpret_cast<const char*>(UTF8String.c_str()) << std::endl;

	// UTF-16 ���ڿ� ���
	// UTF_16 ���ڿ��� UTF-8�� ��ȯ�ϴ� ���� �Լ� ���� (std::string ������ ���ڿ����� ��ȯ)
	auto utf16ToUtf8 = [](const std::u16string& UTF16String) -> std::string
		{
		// UTF-16 ���ڿ��� ��������� �� ���ڿ� ��ȯ
		if (UTF16String.empty()) return {};

		// UTF-16 ���ڿ��� ���̸� ���� ��ȯ �� �ʿ��� ������ ũ�� ��� (���� ��ȯ �������� ����)
		int sizeNeeded = WideCharToMultiByte(
			CP_UTF8, 0,
			reinterpret_cast<LPCWCH>(UTF16String.c_str()),
			static_cast<int>(UTF16String.size()),
			nullptr, 0, nullptr, nullptr
		);

		// ��ȯ�� ���ڿ� ����
		std::string utf8Str(sizeNeeded, 0);
		// UTF-16 ���ڿ��� UTF-8 ���ڿ��� ��ȯ
		WideCharToMultiByte(
			CP_UTF8, 0,
			reinterpret_cast<LPCWCH>(UTF16String.c_str()),
			static_cast<int>(UTF16String.size()),
			utf8Str.data(), sizeNeeded, nullptr, nullptr
		);

		// ��ȯ�� UTF-8 ���ڿ� ��ȯ
		return utf8Str;
		};

	// UTF-16 ���ڿ��� UTF-8�� ��ȯ�Ͽ� ���
	std::cout << utf16ToUtf8(UTF16String) << std::endl;

	return 0;
}