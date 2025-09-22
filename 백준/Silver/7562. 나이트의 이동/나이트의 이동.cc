#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int N;
pair<int, int> startpoint, endpoint;

pair<int, int> dir[8] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };//오른쪽 위부터 시계방향 y,x

int arr[300][300];	//0,1 안씀 2~301 302,303안씀

void Solve()
{
	int TESTCASE;
	cin >> TESTCASE;

	while (TESTCASE--)
	{
		cin >> N;
		cin >> startpoint.first >> startpoint.second >> endpoint.first >> endpoint.second;

		queue<pair<int, int>> Q;
		Q.emplace(startpoint);

		while (!Q.empty())
		{
			pair<int, int> currpoint = Q.front();
			Q.pop();

			if (currpoint == endpoint)
			{
				cout << arr[endpoint.second][endpoint.first] << '\n';
				break;
			}

			for (int i{ 0 }; i < 8; ++i)
			{
				int ny = currpoint.second + dir[i].first;
				int nx = currpoint.first + dir[i].second;

				if (ny < 0 || ny >= N || nx < 0 || nx >= N || arr[ny][nx] != 0)
				{
					continue;
				}

				Q.emplace(nx, ny);
				arr[ny][nx] = arr[currpoint.second][currpoint.first] + 1;
			}
		}

		memset(arr[0], 0, 4 * 300 * 300);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solve();

	return 0;
}