#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Node {
private:
	T data;
	Node<T>* parent;
	vector<Node<T>*> children;
public:
	Node<T>(T data)
	{
		this->data = data;
		parent = NULL;
	}
	T getData()
	{
		return data;
	}
	Node<T>* getParent()
	{
		return parent;
	}
	vector<Node<T>*> getChildren()
	{
		return children;
	}
	void pushChild(T data)
	{
		Node<T>* kid = new Node<T>(data);
		children.push_back(kid);
		kid->parent = this;
	}
};
template<typename T>
class Tree
{
private:
	int num = 0;
	Node<T>* root = NULL;
	vector<Node<T>*> nodes;
public:
	Tree<T>(T data = 0)// 트리 객체 생성시 루트 만들어줌
	{
		root = new Node<T>(data);
		nodes.push_back(root);
	}
	int size()
	{
		return num;
	}
	bool empty()
	{
		return root == NULL;
	}
	Node<T>* getRoot()
	{
		return root;
	}
	vector<Node<T>*> getNodes()
	{
		return nodes;
	}
	bool isRoot(Node<T>* p)
	{
		return (p == root);
	}
	bool isExternal(Node<T>* p)
	{
		return (p->children.size() == 0);
	}//// 여기까진 문제없음//
	/////////////////////////////////////////////////////////////////////
	Node<T>* search(T data, Node<T>* p = NULL)
	{
		if (p == NULL)
			p = root;
		if (p->getData() == data)//@subTree의 Root 가 찾던 노드인가
			return p;
		else
		{
			vector<Node<T>*> kids = p->getChildren();
			Node<T>* cor = NULL;
			for (int i = 0; i < kids.size(); i++)//아니면 자식들로 똑같은짓 다시함
			{
				if (cor != NULL)//@NULL 이 아니다 --> 어딘가에서 NULL이 아닌값 리턴해줌 ( 찾던 포인터값 )
					break;
				cor = search(data, kids[i]);
			}
			return cor;//@찾았으면 NULL이 아닐거고 못찾았으면 NULL 일 거임
		}
	}
	void insertNode(T target, T newNode)
	{
		Node<T>* tNode = search(target);
		//@target 이 없을때
		if (tNode == NULL)
			return;
		if (search(newNode) == NULL)
		{
			Node<T>* nNode = new Node<T>(newNode);
			tNode->pushChild(newNode);
			nodes.push_back(nNode);
			num++;
		}
	}
	void preOrder(Node<T>* p = NULL, int type = 0)
	{
		if (p == NULL)
			p = root;
		visit(p);
		vector<Node<T>*> temp = p->getChildren();
		for (size_t i = 0; i < temp.size(); i++)
		{
			preOrder(temp[i], type);
		}
	}
	void postOrder(Node<T>* p = NULL, int type = 0)
	{
		if (p == NULL)
			p = root;
		vector<Node<T>*> temp = p->getChildren();
		for (size_t i = 0; i < temp.size(); i++)
		{
			postOrder(temp[i], type);
		}
		visit(p);
	}
	int deleteSubTree(T data)
	{
		Node<T>* target = search(data);
		if (target != NULL)
			postOrder(target, 1);
		return 0;
	}
	void visit(Node<T>* p, int type = 0)
	{
		if (type == 0)
		{
			//출력
			cout << p->getData();
		}
		if (type == 1)
		{
			delete p;
		}
	}
};
int main()
{
	int T;
	Tree<char> tr('A');
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.')
		{
			tr.insertNode(a, b);
		}
		if (c != '.')
		{
			tr.insertNode(a, c);
		}
	}
	tr.postOrder(tr.getRoot());
	cout << endl;
	tr.preOrder(tr.getRoot());
	cout << endl;
	return 0;
}