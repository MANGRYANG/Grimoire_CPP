	/*

		���� ��� ���� �ڵ�

	*/


	// �θ� Ŭ���� 1
	class Parent1
	{
	public:
		int member1_p = 0;
	};

	// �θ� Ŭ���� 2
	class Parent2
	{
	public:
		int member2_p = 0;
	};

	// �ڽ� Ŭ���� 1
	// Parent1�� ��������� public ���, Parent2�� ���� ������ ���� -> �⺻���� private ���
	class Child1 : public Parent1, Parent2
	{
	};

	// �ڽ� Ŭ���� 2
	class Child2 : public Parent1, public Parent2
	{
	};


	int main(void)
	{
		Child1 child1;

		child1.member1_p = 10;  // Parent1�� ����� ����
		// child1.member2_p = 20;  // ������ ����: Parent2�� Child1�� private ��ӵǾ� �ܺο��� ���� �Ұ�

		Child2 child2;
		child2.member1_p = 30;  // Parent1�� ����� ����
		child2.member2_p = 40;  // Parent2�� ����� ����
	
		return 0;
	}