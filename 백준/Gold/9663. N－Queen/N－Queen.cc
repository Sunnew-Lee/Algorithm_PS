#include <iostream>
using namespace std;

bool is_used[3][40];	// [0]->vert [1]->leftdown [2]->rightdown
int N, complete;

void func(int row)
{
	if (row == N)
	{
		complete++;
		return;
	}

	for (int i{ 0 }; i < N; i++)
	{
		if (is_used[0][i] || is_used[1][i + row] || is_used[2][i - row])
			continue;

		is_used[0][i] = true;
		is_used[1][i + row] = true;
		is_used[2][i - row] = true;
		func(row + 1);
		is_used[0][i] = false;
		is_used[1][i + row] = false;
		is_used[2][i - row] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;

	func(0);
	cout << complete;

	return 0;
}