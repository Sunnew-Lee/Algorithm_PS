#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
vector<pair<int, int>> adj[20001];
int d[20001];
int INF = 200001;

void Dijkstra(int s)
{
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
	PQ.push({ 0,s });
	d[s] = 0;

	while (!PQ.empty())
	{
		pair<int, int> temp = PQ.top();
		PQ.pop();

		if (d[temp.second] != temp.first)
		{
			continue;
		}

		for (pair<int, int>& p : adj[temp.second])
		{
			//d[] 가 더 크면 d[현재]+w로 업데이트 한다 
			if (d[p.second] > d[temp.second] + p.first)
			{
				d[p.second] = d[temp.second] + p.first;
				PQ.push({ d[p.second] ,p.second });
			}			
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int start;
	cin >> V >> E >> start;

	fill(d, d + V+1, INF);

	for (int i{ 0 }; i < E; ++i)
	{
		int s, t, w;
		cin >> s >> t >> w;
		adj[s].push_back({ w, t });
	}

	Dijkstra(start);

	for (int i{ 1 }; i <= V; ++i)
	{
		if (d[i]==INF)
		{
			cout << "INF\n";
			continue;
		}

		cout << d[i]<<'\n';
	}

	return 0;
}