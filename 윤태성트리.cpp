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
	Tree<T>(T data = 0)// Ʈ�� ��ü ������ ��Ʈ �������
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
	}//// ������� ��������//
	/////////////////////////////////////////////////////////////////////
	Node<T>* search(T data, Node<T>* p = NULL)
	{
		if (p == NULL)
			p = root;
		if (p->getData() == data)//@subTree�� Root �� ã�� ����ΰ�
			return p;
		else
		{
			vector<Node<T>*> kids = p->getChildren();
			Node<T>* cor = NULL;
			for (int i = 0; i < kids.size(); i++)//�ƴϸ� �ڽĵ�� �Ȱ����� �ٽ���
			{
				if (cor != NULL)//@NULL �� �ƴϴ� --> ��򰡿��� NULL�� �ƴѰ� �������� ( ã�� �����Ͱ� )
					break;
				cor = search(data, kids[i]);
			}
			return cor;//@ã������ NULL�� �ƴҰŰ� ��ã������ NULL �� ����
		}
	}
	void insertNode(T target, T newNode)
	{
		Node<T>* tNode = search(target);
		//@target �� ������
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
			//���
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