#include <iostream>
#include <vector>
using namespace std;
enum direction {MIN = 1, MAX = -1};


class Heap
{
public:
	vector<int> v;
	int rootindex = 1;
	int heapsize;
	int direction;
	Heap(int dir) {
		v.push_back(-1);
		this->heapsize = 0;
		this->direction = dir;
	}

	void print()
	{
		for (int i = 1; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
	}

	void swapN(int index1, int index2)
	{
		v[0] = v[index1];
		v[index1] = v[index2];
		v[index2] = v[0];
	}

	void insert(int num)
	{
		v.push_back(num);
		heapsize++;
		Upheap(heapsize);
	}

	void Upheap(int index)
	{
		if (index == rootindex)
		{
			return;
		}
		int parent = index / 2;
		if (v[parent]*direction > v[index] * direction)
		{
			swapN(parent, index);
			Upheap(parent);
		}
		else
		{
			return;
		}
	}

	int remove()
	{
		int tmp = v[1];
		v[1] = v[heapsize];
		v.pop_back();
		heapsize--;
		Downheap(1);
		return tmp;
	}

	void decrease_key(int p, int i)
	{
		if (v[p] < i) return;
		v[p] = i;
		Upheap(p);
	}
	
	void sort()
	{
		vector<int> sorted;
		while (heapsize != 0)
		{
			sorted.push_back(remove());
		}
		for (int i = 0; i < sorted.size(); i++)
		{
			cout << sorted[i] << " ";
		}
		cout << "\n";
	}

	void Downheap(int index)
	{
		int left = 2 * index;
		int right = 2 * index + 1;

		if (right <= heapsize) // 자식이 둘다있을때
		{
			if (v[left] * direction > v[right] * direction)
			{
				if (v[index] * direction > v[right] * direction)
				{
					swapN(index, right);
					Downheap(right);
				}
				else
				{
					return;
				}
			}
			else
			{
				if (v[index] * direction > v[left] * direction)
				{
					swapN(index, left);
					Downheap(left);
				}
				else
				{
					return;
				}
			}
		}
		else
		{
			if (left <= heapsize)
			{
				if (v[left] * direction < v[index] * direction)
				{
					swapN(left, index);
					Downheap(left);
				}
				else
				{
					return;
				}
			}
			else
			{
				return;
			}
		}
	}

};


Heap h(MIN);
int n;
int m;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		h.insert(m);
	}
	h.print();
	h.sort();


	return 0;
}