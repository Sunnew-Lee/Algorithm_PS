// 시작점이 주어진 게 아니라 모든 점을 시작점으로 고려해야함.
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, r;
	cin >> n >> m >> r;

	int MAX = n * 100 + 1;
	vector<vector<int>> floyd(n + 1, vector<int>(n + 1, MAX));

	vector<int> item(n, 0);
	for (int i{ 0 }; i < n; ++i)
	{
		cin >> item[i];
	}

	while (r--)
	{
		int s, t, l;
		cin >> s >> t >> l;

		if (floyd[s][t] > l)
		{
			floyd[s][t] = l;
			floyd[t][s] = l;
		}
	}

	for (int i{ 1 }; i <= n; ++i)
	{
		floyd[i][i] = 0;
	}

	for (int i{ 1 }; i <= n; ++i)
	{
		for (int s{ 1 }; s <= n; ++s)
		{
			for (int t{ 1 }; t <= n; ++t)
			{
				int w = floyd[s][i] + floyd[i][t];
				if (floyd[s][t] > w)
				{
					floyd[s][t] = w;
					floyd[t][s] = w;
				}
			}
		}
	}

	int answer{ -1 };
	for (int i{ 1 }; i <= n; ++i)
	{
		int sum{ 0 };
		for (int j{ 1 }; j <= n; ++j)
		{
			if (floyd[i][j] > m)
			{
				continue;
			}

			sum += item[j-1];
		}
		answer = max(answer, sum);
	}

	cout << answer;

	return 0;
}