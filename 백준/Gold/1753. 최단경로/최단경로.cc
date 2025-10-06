#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int V, E;
vector<pair<int, int>> adj[20001];
int d[20001];
//bool fix[20001];
int INF = 200001;


//void Dijkstra(int s)
//{
//	d[s] = 0;
//	//fix[s] = true;
//	//int index = s;
//
//	while (1)
//	{
//		//d[]에서 가장 작은 값의 인덱스를 확정시킨다.
//		int w = INF;
//		int index = -1;
//		for (int i{ 1 }; i <= V; ++i)
//		{
//			if (fix[i])
//				continue;
//
//			if (w > d[i])
//			{
//				w = d[i];
//				index = i;
//			}
//		}
//
//		//모든 인덱스가 확정되면 종료한다.
//		if (index == -1)
//			break;
//
//		//이번에 찾은 놈들 중 가장 작은 w의 인덱스를 확정한다
//		fix[index] = true;
//		//index = next;
//
//		//현재 인덱스에서 갈 수 있는 곳 본다
//		for (pair<int, int>& p : adj[index])
//		{
//			// 어차피 fix이면 업데이트 될 일이 없음.
//			//if (fix[p.second])
//			//	continue;
//
//			//d[] 가 더 크면 d[현재]+w로 업데이트 한다 
//			if (d[p.second] > d[index] + p.first)
//			{
//				d[p.second] = d[index] + p.first;
//			}
//		}
//	}
//}

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