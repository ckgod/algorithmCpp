#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
	int elem; // 노드의 정보
	int storage; // 노드의 용량
	int allstor; // 하위노드용량과 자기용량 합
	int depth = 0; // 깊이
	node* parent;
	vector<node*> child;
	node()
	{
		this->allstor = 0;
		this->depth = 0;
		this->storage = 0;
		this->elem = 0;
		parent = NULL;
	}
	node(int n)
	{
		this->allstor = 0;
		this->depth = 0;
		this->storage = 0;
		this->elem = n;
		parent = NULL;
	}
	int getAllStor() 
	{
		return this->allstor;
	}
	int getelem()
	{
		return this->elem;
	}
	int getParent()
	{
		return parent->elem;
	}
	void pushChild(node* ch) // 자식노드추가
	{
		this->child.push_back(ch);
	}
	void setParent(node* p) // 부모노드설정
	{
		this->parent = p;
	}
	void delChild(node* c) // 자식노드 삭제
	{
		for (unsigned int i = 0; i < this->child.size(); i++)
		{
			if (this->child[i] == c)
			{
				this->child.erase(this->child.begin() + i);
			}
		}
	}
};

class tree
{
public:
	node* root = new node();
	vector<node*> nodelist; // 추가한 노드의 모든정보저장
	int treesize = 0;
	tree()
	{
		this->root = NULL;
	}
	tree(int e)
	{
		this->root->elem = e;
		nodelist.push_back(root);
	}
public:
	void setStorage(int p, int s) // p위치노드의 storage에 s입력
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == p)
			{
				nodelist[i]->storage = s;
			}
		}
	}
	void sumStorage(node* alls, node* vroot) // alls노드의 allstor에 postorder를이용해서 하위노드들의 용량을 모두더함
	{
		for (int i = 0; i < vroot->child.size(); i++)
		{
			sumStorage(alls, vroot->child[i]);
		}
		alls->allstor += vroot->storage;
	}
	void insertNode(int p, int e) // p위치노드에 e를가진 자식을 추가
	{
		node* newleaf = new node(e);
	//	node* cur;
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == p)
			{
				nodelist[i]->pushChild(newleaf);
				newleaf->setParent(nodelist[i]);
				nodelist.push_back(newleaf);
				newleaf->depth = newleaf->parent->depth + 1;
				/*cur = nodelist[i];
				cur->pushChild(newleaf);
				newleaf->setParent(cur);
				newleaf->depth = newleaf->parent->depth + 1;
				nodelist.push_back(newleaf);*/
			}
		}
	}

	void printChild(int pe) // pe위치노드의 자식들 정보 출력
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == pe)
			{
				if (nodelist[i]->child.size() == 0)
				{
					cout << "0\n";
				}
				else
				{
					for (int j = 0; j < nodelist[i]->child.size(); j++)
					{
						cout << nodelist[i]->child[j]->elem << " ";
					}
					cout << "\n";
				}
			}
		}
	}
	void printParent(int c)
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == c)
			{
				if (nodelist[i]->parent == NULL)
				{
					cout << "root!\n";
				}
				else
				{
					cout << nodelist[i]->getParent() << "\n";
				}
			}
		}
	}
	void printDepth(int position)
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == position)
			{
				cout << nodelist[i]->depth << "\n";
			}
		}
	}

	node* search(int elem) // elem정보를가진 노드검색 주소반환
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			if (nodelist[i]->elem == elem)
			{
				return nodelist[i];
			}
		}
	}

	// Travasal  -> 트리의 모든노드를 한번씩 처리할 수 있음

	void preOrder(node* vroot) // 프리오더 : 자기먼저 처리->하위처리
	{
		cout << vroot->elem << " ";
		for (int i = 0; i < vroot->child.size(); i++)
		{
			preOrder(vroot->child[i]);
		}
	}

	void postOrder(node* vroot) // 포스트오더 : 최하위부터 처리
	{
		for (int i = 0; i < vroot->child.size(); i++)
		{
			postOrder(vroot->child[i]);
		}
		cout << vroot->elem << " ";
	}

	////////////////////////////////

	bool isroot()
	{

	}
	bool isexternal()
	{

	}
};

int N, M;
tree T1(1);
int stor[27];
int nn, st;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int tmp = N;
	for (int i = 0; i < N; i++)
	{
		cin >> nn >> st;
		stor[nn] = st;
	}
	while (N--)
	{
		vector<int> num;
		for (int i = 0; i < 7; i++)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 0) break;
			num.push_back(tmp);
		}
		for (int i = 1; i < num.size(); i++)
		{
			T1.insertNode(num[0], num[i]);
		}
	}
	N = tmp;
	for (int i = 1; i <= N; i++)
	{
		T1.setStorage(i, stor[i]);
	}
	while (M--)
	{
		int fp;
		cin >> fp;
		if (T1.search(fp)->allstor == 0)
		{
			T1.sumStorage(T1.search(fp), T1.search(fp));
		}
		cout << T1.search(fp)->allstor << "\n";
	}
	//int p = 0;
	//T1.preOrder(T1.root);
	//cout << "\n";
	//T1.postOrder(T1.root);
	//while (M--)
	//{
	//	cin >> p;
	//	T1.printDepth(p);
	//	T1.printChild(p);
	//	T1.printParent(p);
	//}


	return 0;
}