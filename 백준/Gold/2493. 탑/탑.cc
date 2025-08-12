#include <iostream>
#include <stack>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N, tower;
	cin >> N;

	stack<pair<int, int>> S;
	S.emplace(100000001, 0);

	for (int i{ 1 }; i <= N; ++i)
	{
		cin >> tower;

		while (tower >= S.top().first)
		{
			S.pop();
		}

		cout << S.top().second << ' ';
		S.emplace(tower, i);
	}

	return 0;
}