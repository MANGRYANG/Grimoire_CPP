	/*

		다중 상속 예시 코드

	*/


	// 부모 클래스 1
	class Parent1
	{
	public:
		int member1_p = 0;
	};

	// 부모 클래스 2
	class Parent2
	{
	public:
		int member2_p = 0;
	};

	// 자식 클래스 1
	// Parent1은 명시적으로 public 상속, Parent2는 접근 지정자 생략 -> 기본값인 private 상속
	class Child1 : public Parent1, Parent2
	{
	};

	// 자식 클래스 2
	class Child2 : public Parent1, public Parent2
	{
	};


	int main(void)
	{
		Child1 child1;

		child1.member1_p = 10;  // Parent1의 멤버에 접근
		// child1.member2_p = 20;  // 컴파일 에러: Parent2가 Child1에 private 상속되어 외부에서 접근 불가

		Child2 child2;
		child2.member1_p = 30;  // Parent1의 멤버에 접근
		child2.member2_p = 40;  // Parent2의 멤버에 접근
	
		return 0;
	}