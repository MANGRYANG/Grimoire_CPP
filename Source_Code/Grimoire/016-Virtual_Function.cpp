/*

	Virtual Function 예시 코드

*/

#include <iostream>

// 부모 클래스
class Parent
{
public:
    void foo()  // 일반 멤버 함수 정의
    {
        std::cout << "Parent\n";
    }

    virtual void foo_virtual()  // virtual 키워드를 사용하여 가상 멤버 함수 정의
    {
        std::cout << "Parent-Virtual\n";
    }
};

// 자식 클래스
class Child : public Parent
{
public:
	void foo()  // 부모 클래스의 일반 함수를 같은 이름으로 정의
    {
        std::cout << "Child\n";
    }

	void foo_virtual() override // 부모 클래스의 virtual 함수를 오버라이드
	{
		std::cout << "Child-Virtual\n";
	}
};

int main(void)
{
    // 부모 타입 포인터를 선언하고 자식 클래스의 객체를 생성하여 할당 : 업캐스팅
    Parent* p = new Child();

    // foo()는 virtual이 아니므로 정적 바인딩이 발생함
    // 정적 바인딩 : 컴파일 타임에 어떤 함수가 호출될 지 결정되는 방식
    // 컴파일 시점에 Parent::foo 호출로 결정됨
    // Child::foo는 함수 숨김(name hiding)으로 인해 호출되지 않음
    p->foo();  // Parent::foo 호출
    
    // foo_virtual()은 virtual이므로 동적 바인딩 발생
    // 동적 바인딩: 실행 시간에 실제 객체 타입을 보고 호출할 함수 결정
    // p가 Child 객체를 가리키므로 Child::foo_virtual이 호출됨
	p->foo_virtual();  // Child::foo_virtual 호출 
}