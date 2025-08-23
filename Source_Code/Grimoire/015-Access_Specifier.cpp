/*

	���� ������ ���� �ڵ�

	�θ� Ŭ���������� �ڽ� Ŭ������ private, protected, public ����� ��� ������ �� ����.
	�ݸ� �ڽ� Ŭ���������� ���� Ŭ������ private�� ������ protected, public ����� ���� �����ϴ�.
	
	�̴� �ܿ� �θ�-�ڽ� ���谡 �ƴ� ����-�ڼ� ���迡�� ��� ����ȴ�.

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
	
	// �θ� Ŭ���� A�� private ����� ����
	int getA_Private() const
	{
		return A::a_private; // A Ŭ������ private ����� ���� -> ���� �Ұ�
	}
	
	*/

	// �θ� Ŭ���� A�� protected ����� ����
	int getA_Protected() const
	{
		return A::a_protected; // A Ŭ������ protected ����� ���� -> ���� ����
	}

	// �θ� Ŭ���� A�� public ����� ����
	int getA_Public() const
	{
		return A::a_public; // A Ŭ������ public ����� ���� -> ���� ����
	}

	/*
	
	// �ڽ� Ŭ���� C�� private ����� ����
	int getC_Private() const
	{
		return C::c_private; // C Ŭ������ private ����� ���� -> ���� �Ұ�
	}

	*/


	/*
	
	// �ڽ� Ŭ���� C�� protected ����� ����
	int getC_Protected() const
	{
		return C::c_protected; // C Ŭ������ protected ����� ���� -> ���� �Ұ�
	}

	// �ڽ� Ŭ���� C�� public ����� ����
	int getC_Public() const
	{
		return C::c_public; // C Ŭ������ public ����� ���� -> ���� �Ұ�
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
	
	// ���θ� Ŭ���� A�� private ����� ����
	int getA_Private() const
	{
		return A::a_private; // A Ŭ������ private ����� ���� -> ���� �Ұ�
	}

	*/

	// ���θ� Ŭ���� A�� protected ����� ����
	int getA_Protected() const
	{
		return A::a_protected; // A Ŭ������ protected ����� ���� -> ���� ����
	}

	// ���θ� Ŭ���� A�� public ����� ����
	int getA_Public() const
	{
		return A::a_public; // A Ŭ������ public ����� ���� -> ���� ����
	}
};

int main(void)
{
	A a;
	B b;
	C c;

	return 0;
}