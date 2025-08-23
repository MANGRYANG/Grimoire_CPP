/*

	접근 지정자 예시 코드

	부모 클래스에서는 자식 클래스의 private, protected, public 멤버에 모두 접근할 수 없다.
	반면 자식 클래스에서는 조상 클래스의 private를 제외한 protected, public 멤버에 접근 가능하다.
	
	이는 단연 부모-자식 관계가 아닌 조상-자손 관계에서 모두 적용된다.

*/

class A
{
private:
	int a_private = 0;
protected:
	int a_protected = 0;
public:
	int a_public = 0;
};

class B : public A
{
private:
	int b_private = 0;
protected:
	int b_protected = 0;
public:
	int b_public = 0;

	/*
	
	// 부모 클래스 A의 private 멤버에 접근
	int getA_Private() const
	{
		return A::a_private; // A 클래스의 private 멤버에 접근 -> 접근 불가
	}
	
	*/

	// 부모 클래스 A의 protected 멤버에 접근
	int getA_Protected() const
	{
		return A::a_protected; // A 클래스의 protected 멤버에 접근 -> 접근 가능
	}

	// 부모 클래스 A의 public 멤버에 접근
	int getA_Public() const
	{
		return A::a_public; // A 클래스의 public 멤버에 접근 -> 접근 가능
	}

	/*
	
	// 자식 클래스 C의 private 멤버에 접근
	int getC_Private() const
	{
		return C::c_private; // C 클래스의 private 멤버에 접근 -> 접근 불가
	}

	*/


	/*
	
	// 자식 클래스 C의 protected 멤버에 접근
	int getC_Protected() const
	{
		return C::c_protected; // C 클래스의 protected 멤버에 접근 -> 접근 불가
	}

	// 자식 클래스 C의 public 멤버에 접근
	int getC_Public() const
	{
		return C::c_public; // C 클래스의 public 멤버에 접근 -> 접근 불가
	}

	*/

};

class C : public B
{
private:
	int c_private = 0;
protected:
	int c_protected = 0;
public:
	int c_public = 0;


	/*
	
	// 조부모 클래스 A의 private 멤버에 접근
	int getA_Private() const
	{
		return A::a_private; // A 클래스의 private 멤버에 접근 -> 접근 불가
	}

	*/

	// 조부모 클래스 A의 protected 멤버에 접근
	int getA_Protected() const
	{
		return A::a_protected; // A 클래스의 protected 멤버에 접근 -> 접근 가능
	}

	// 조부모 클래스 A의 public 멤버에 접근
	int getA_Public() const
	{
		return A::a_public; // A 클래스의 public 멤버에 접근 -> 접근 가능
	}
};

int main(void)
{
	A a;
	B b;
	C c;

	return 0;
}