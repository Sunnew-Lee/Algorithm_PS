//O(1)로 가능한지 여부 파악이 핵심.
#include <iostream>
#include <tuple>

using namespace std;
int N, answer;


//mask colunm 0~N-1, diagonal 0~2N-2, diagonal 0~2N-2 표현 가능
void DFS(int row, tuple<int,int,int> mask )
{
	if (row == N)
	{
		++answer;
		return;
	}


	for (int x{ 0 }; x < N; ++x)
	{
		int col, dig_right, dig_left;
		tie(col, dig_right, dig_left) = mask;

		if ( col & (1 << x) || dig_right & (1 << (x - row + N - 1)) || dig_left & (1 << (x + row)) )
		{
			continue;
		}

		DFS(row + 1, { col | (1 << x),dig_right | (1 << (x - row + N - 1)), dig_left | (1 << (x + row)) });
	}

}

void Solve()
{
	cin >> N;

	DFS(0, { 0,0,0 });

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solve();

	return 0;
}