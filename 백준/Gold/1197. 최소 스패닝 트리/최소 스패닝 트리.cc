#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<bool> node(V + 1, false);    // 각 정점이 탐색되었는지
    vector<vector<pair<int, int>>> adj(V + 1);  // 각 정점번호 당 이어져있는 간선과 그 간선의 가중치를 저장
    //vector<int> value(E);

    for (int i{ 0 };i<E;++i)
    {
        int s, t, w;    // start, target, weight
        cin >> s >> t >> w;
        adj[s].push_back({ w,t });
        adj[t].push_back({ w,s });
    }


    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> PQ;    // 비용, 도착정점

    node[1] = true;
    for (pair<int, int>& p : adj[1])
    {
        PQ.push({ p.first,p.second });
    }

    int total{ 0 };
    int checked{ 1 };

    while (checked < V)
    {
        pair<int, int> temp = PQ.top(); PQ.pop();
        if (node[temp.second] == true)
        {
            continue;
        }

        node[temp.second] = true;
        total += temp.first;
        ++checked;

        for (pair<int, int>& p : adj[temp.second])
        {
            if (node[p.second] == true)
            {
                continue;
            }

            PQ.push({ p.first,p.second });
        }
    }

    cout << total;

    return 0;
}