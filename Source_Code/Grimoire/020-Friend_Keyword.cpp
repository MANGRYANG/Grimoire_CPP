/*

	Friend Keyword 사용 예시 코드

*/

#include <iostream>

class Vector
{
private:
	// x, y 좌표를 private 멤버 변수로 선언하여 외부 접근 차단
	int x, y;
public:
	// 생성자
	Vector(int x_val, int y_val) : x(x_val), y(y_val) {};

	// 멤버 변수 출력 함수
	void print_vec() const
	{
		std::cout << "X: " << x << ", Y: " << y << std::endl;
	}

	friend Vector operator+(const int num, const Vector& vec);
};

Vector operator+(const int num, const Vector& vec)
{
	// friend로 선언된 operator+ 함수는 Vector 클래스의 private 멤버에 접근 가능
	return Vector(num + vec.x, num + vec.y);
}

int main(void)
{
	Vector vec(1, 2);
	
	vec.print_vec();  // X: 1, Y: 2

	vec = 10 + vec;  // friend로 선언된 operator+ 함수 호출

	vec.print_vec();  // X: 11, Y: 12

	return 0;
}