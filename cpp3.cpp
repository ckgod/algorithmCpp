#include <iostream>
using namespace std;




struct node //노드는 데이터를 저장할 변수와 다음노드의 주소를 저장할 
	        //자기참조 구조체 포인터변수를 하나 가지고있다.
{
	int value;
	struct node* next; //선언한 노드 구조체의 주소를 저장할 수 있다.
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	node* head = new node; // 머리노드 생성
	head->next = NULL; // 머리노드의 next값은 null이다.

	node* node1 = new node;
	node1->value = 10;
	node1->next = head->next; // node1의 다음 주소는 머리노드가 가리키던 다음주소
							  // NULL을 저장
	head->next = node1;		  // 머리노드의 다음노드는 node1의 주소를 저장.


	node* node2 = new node;
	node2->value = 20;
	node2->next = head->next;
	head->next = node2;

	node* ptr = new node; // 노드를 쭉 스캔할 ptr구조체 포인터
	ptr = head->next; // 머리노드가 가리키는 주소를 넣음
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