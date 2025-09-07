#include <iostream>
#include <vector>

using namespace std;
vector<int> heap;	//min heap

void reorder_topdown(int index)
{
	//heap size check so no over bound + return
	int size = heap.size();
	int _min;
	int root{ heap[index] }, left, right;

	if (size <= index * 2 + 1)
	{
		return;
	}
	else if (size == index * 2 + 2)
	{
		left = heap[index * 2 + 1];
		_min = min(root, left);
	}
	else
	{
		left = heap[index * 2 + 1];
		right = heap[index * 2 + 2];
		_min = min(root, min(left, right));
	}
	
	if (_min == root)
	{
		return;
	}

	else if (_min == left)
	{
		swap(heap[index], heap[index * 2 + 1]);
		reorder_topdown(index * 2 + 1);
	}

	else if (_min == right)
	{
		swap(heap[index], heap[index * 2 + 2]);
		reorder_topdown(index * 2 + 2);
	}
}

void reorder_bottomup(int index)
{
	//check if no parent
	if (index == 0)
		return;

	int root_idx{ index / 2 };
	int _min;
	if ((index & 1) == false)
	{
		--root_idx;
	}

	_min = min(heap[root_idx], heap[index]);

	if (_min == heap[index])
	{
		swap(heap[root_idx], heap[index]);
	}

	reorder_bottomup(root_idx);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,op;
	cin >> N;

	while (N--)
	{
		cin >> op;

		//print&erase
		//size-1과 swap후, 내려가면서 swap 진행.
		if (op == 0)
		{
			if (heap.empty())
			{
				cout << 0 << '\n';
				continue;
			}

			cout << heap[0] << '\n';
			swap(heap[0], heap[heap.size() - 1]);
			heap.pop_back();

			if (heap.empty())
			{
				continue;
			}
			reorder_topdown(0);
			continue;
		}

		//else insert to heap;
		//size+1로 어디 입력해야하는지 찾고, swap 진행
		heap.push_back(op);
		reorder_bottomup(heap.size() - 1);

	}

	return 0;
}