#include <iostream>
using namespace std;




struct node //���� �����͸� ������ ������ ��������� �ּҸ� ������ 
	        //�ڱ����� ����ü �����ͺ����� �ϳ� �������ִ�.
{
	int value;
	struct node* next; //������ ��� ����ü�� �ּҸ� ������ �� �ִ�.
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	node* head = new node; // �Ӹ���� ����
	head->next = NULL; // �Ӹ������ next���� null�̴�.

	node* node1 = new node;
	node1->value = 10;
	node1->next = head->next; // node1�� ���� �ּҴ� �Ӹ���尡 ����Ű�� �����ּ�
							  // NULL�� ����
	head->next = node1;		  // �Ӹ������ �������� node1�� �ּҸ� ����.


	node* node2 = new node;
	node2->value = 20;
	node2->next = head->next;
	head->next = node2;

	node* ptr = new node; // ��带 �� ��ĵ�� ptr����ü ������
	ptr = head->next; // �Ӹ���尡 ����Ű�� �ּҸ� ����
	while (ptr != NULL)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}


	delete head;
	delete node1;
	delete node2;


	return 0;
}