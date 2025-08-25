/*

	Friend Keyword ��� ���� �ڵ�

*/

#include <iostream>

class Vector
{
private:
	// x, y ��ǥ�� private ��� ������ �����Ͽ� �ܺ� ���� ����
	int x, y;
public:
	// ������
	Vector(int x_val, int y_val) : x(x_val), y(y_val) {};

	// ��� ���� ��� �Լ�
	void print_vec() const
	{
		std::cout << "X: " << x << ", Y: " << y << std::endl;
	}

	friend Vector operator+(const int num, const Vector& vec);
};

Vector operator+(const int num, const Vector& vec)
{
	// friend�� ����� operator+ �Լ��� Vector Ŭ������ private ����� ���� ����
	return Vector(num + vec.x, num + vec.y);
}

int main(void)
{
	Vector vec(1, 2);
	
	vec.print_vec();  // X: 1, Y: 2

	vec = 10 + vec;  // friend�� ����� operator+ �Լ� ȣ��

	vec.print_vec();  // X: 11, Y: 12

	return 0;
}