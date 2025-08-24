/*

	상속 접근 지정자 예시 코드

*/

#include <iostream>

// 부모 클래스
class Parent
{
	// Private 멤버 변수 및 함수는 자식 클래스에서 접근할 수 없기 때문에 작성하지 않음
private:
	// Protected 멤버 변수 및 함수
protected:
	int protected_member_p = 0;  // protected 멤버 변수
	void protected_function_p()  // protected 멤버 함수
	{
		std::cout << "Protected Function\n";
	}
	// public 멤버 변수 및 함수
public:
	int public_member_p = 0;  // public 멤버 변수
	void public_function_p()  // public 멤버 함수
	{
		std::cout << "Public Function\n";
	}
};

// public으로 부모 클래스 상속
class Child_public : public Parent
{
};

// protected로 부모 클래스 상속
class Child_protected : protected Parent
{
};

// private으로 부모 클래스 상속
class Child_private : private Parent
{
};

// 부모 클래스의 참조를 매개변수로 받는 함수 선언
void func(Parent&);

int main(void)
{
	// 부모 클래스 객체 생성
	Parent parent;
	// 자식 클래스 객체 생성
	Child_public child_public;
	Child_protected child_protected;
	Child_private child_private;

	// 부모 클래스의 객체를 매개변수로 전달
	func(parent);

	// public으로 상속받은 자식 클래스의 객체를 매개변수로 전달
	func(child_public);

	// protected로 상속받은 자식 클래스의 객체를 매개변수로 전달
	// 
	// func(child_protected);
	
	// private로 상속받은 자식 클래스의 객체를 매개변수로 전달
	// private 접근 지정자를 통해 상속받은 경우 자식 클래스 객체를 부모 클래스 타입으로 변환할 수 없음
	// func(child_private);

	// public 접근 지정자를 통해 상속받은 경우
	// 
	// 부모 클래스의 protected 멤버는 protected으로 취급되어 외부에서 접근할 수 없음
	/*
	child_public.protected_member_p = 10;
	child_public.protected_function_p();
	*/
	// 
	// 부모 클래스의 public 멤버는 public으로 취급되어 외부에서 접근할 수 있음
	child_public.public_member_p = 20;
	child_public.public_function_p();

	// protected 접근 지정자를 통해 상속받은 경우
	// 
	// 부모 클래스의 protected 멤버는 protected으로 취급되어 외부에서 접근할 수 없음
	/*
	child_protected.protected_member_p = 10;
	child_protected.protected_function_p();
	*/
	//
	// 부모 클래스의 public 멤버는 protected으로 취급되어 외부에서 접근할 수 없음
	/*
	child_protected.public_member_p = 20;
	child_protected.public_function_p();
	*/

	// private 접근 지정자를 통해 상속받은 경우
	// 
	// 부모 클래스의 protected 멤버는 private으로 취급되어 외부에서 접근할 수 없음
	/*
	child_private.protected_member_p = 10;  // private 상속으로 인해 접근 불가
	child_private.protected_function_p();  // private 상속으로 인해 접근 불가
	*/
	//
	// 부모 클래스의 public 멤버는 private으로 취급되어 외부에서 접근할 수 없음
	/*
	child_private.public_member_p = 20;  // private 상속으로 인해 접근 불가
	child_private.public_function_p();  // private 상속으로 인해 접근 불가
	*/

	return 0;
}