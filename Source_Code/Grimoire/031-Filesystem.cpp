/*

	Filesystem ���̺귯�� ��� ���� �ڵ�

*/

#include <iostream>
// Filesystem ���̺귯�� ���
#include <filesystem>
// ���� ����� ���
#include <fstream>

int main(void)
{
	// ���丮�� ������ ��� ����
	std::filesystem::path dirPath = "./test_directory";
	// ���丮 ���� (filesystem::create_directory)
	std::filesystem::create_directory(dirPath);

	// ������ ������ ��� ����
	std::filesystem::path filePath = dirPath / "example.txt";
	// ���� ���� �� ���� �ۼ�
	std::ofstream outFile(filePath);
	outFile << "Hello, Filesystem!" << std::endl;
	outFile.close();

	// ���丮 �� ���� ���� �˸� �޽��� ���
	std::cout << "Directory and file created: " << filePath.generic_string() << std::endl;

	// ���� ���丮 ���� ���� Ȯ�� �޽��� ���
	std::cout << "Is directory created successfully? : " << (std::filesystem::exists(dirPath) ? "True" : "False") << std::endl;
	// ���� ���� ���� ���� Ȯ�� �޽��� ���
	std::cout << "Is file created successfully? : " << (std::filesystem::exists(filePath) ? "True" : "False") << std::endl;
	
	// ���丮 �� ���� �׸� ��� ����
	std::filesystem::remove_all(dirPath);
	// ���� �˸� �޽��� ���
	std::cout << "Directory and file removed." << std::endl;
	
	return 0;
}