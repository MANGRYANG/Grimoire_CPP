/*

	Filesystem 라이브러리 사용 예시 코드

*/

#include <iostream>
// Filesystem 라이브러리 헤더
#include <filesystem>
// 파일 입출력 헤더
#include <fstream>

int main(void)
{
	// 디렉토리를 생성할 경로 설정
	std::filesystem::path dirPath = "./test_directory";
	// 디렉토리 생성 (filesystem::create_directory)
	std::filesystem::create_directory(dirPath);

	// 파일을 생성할 경로 설정
	std::filesystem::path filePath = dirPath / "example.txt";
	// 파일 생성 및 내용 작성
	std::ofstream outFile(filePath);
	outFile << "Hello, Filesystem!" << std::endl;
	outFile.close();

	// 디렉토리 및 파일 생성 알림 메시지 출력
	std::cout << "Directory and file created: " << filePath.generic_string() << std::endl;

	// 실제 디렉토리 생성 여부 확인 메시지 출력
	std::cout << "Is directory created successfully? : " << (std::filesystem::exists(dirPath) ? "True" : "False") << std::endl;
	// 실제 파일 생성 여부 확인 메시지 출력
	std::cout << "Is file created successfully? : " << (std::filesystem::exists(filePath) ? "True" : "False") << std::endl;
	
	// 디렉토리 및 하위 항목 모두 삭제
	std::filesystem::remove_all(dirPath);
	// 삭제 알림 메시지 출력
	std::cout << "Directory and file removed." << std::endl;
	
	return 0;
}