#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int MAX = n * 100000 + 1;
	vector<vector<int>> floyd(n + 1, vector<int>(n + 1, MAX));
	vector<vector<int>> nxt(n + 1, vector<int>(n + 1, -1));

	while (m--)
	{
		int s, t, w;
		cin >> s >> t >> w;

		if (floyd[s][t] > w)
		{
			floyd[s][t] = w;
			//floyd[t][s] = w;
		}
		nxt[s][t] = t;
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
				//if (i == s || i == t)
				//	continue;

				int w = floyd[s][i] + floyd[i][t];
				if (floyd[s][t] > w)
				{
					floyd[s][t] = w;
					//floyd[t][s] = w;
					nxt[s][t] = nxt[s][i];
				}
			}
		}
	}

	for (int i{ 1 }; i <= n; ++i)
	{
		for (int j{ 1 }; j <= n; ++j)
		{
			if (floyd[i][j] == MAX)
			{
				cout << "0 ";
				continue;
			}

			cout << floyd[i][j] << ' ';
		}
		cout << '\n';
	}

	
	for (int i{ 1 }; i <= n; ++i)
	{
		for (int j{ 1 }; j <= n; ++j)
		{
			if (nxt[i][j] == -1)
			{
				cout << "0 \n";
				continue;
			}

			vector<int> v(1, i);
			int temp = i;
			while (temp != j)
			{
				temp = nxt[temp][j];
				v.push_back(temp);
			}


			cout << v.size() << ' ';
			for (int num : v)
			{
				cout << num << ' ';
			}
			cout << '\n';
		}		
	}

	return 0;
}