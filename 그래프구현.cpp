#include <iostream>
#include <vector>
using namespace std;
#define INF 99999999

class vertex
{
public:
	int degree;
	int data;
	vertex()
	{
		degree = 0;
		data = 0;
	}
	vertex(int v)
	{
		data = v;
		degree = 0;
	}
};

class edge
{
public:
	vertex* prev;
	vertex* next;
	edge()
	{
		this->prev = NULL;
		this->next = NULL;
	}
};

class graph
{
public:
	vertex* vlist[501];
	edge* elist[1001];
	graph()
	{
		for (int i = 0; i < 501; i++)
		{
			vlist[i] = NULL;
		}
		for (int i = 0; i < 1001; i++)
		{
			elist[i] = NULL;
		}
	}

	void insertV(int v)
	{
		if (vlist[v] != NULL) return;
		vertex* newv = new vertex(v);
		vlist[v] = newv;
	}

	void insertE(int v1, int v2)
	{
		if (vlist[v1] == NULL || vlist[v2] == NULL) return;
		
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	return 0;
}