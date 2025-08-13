#include <iostream>
#include <queue>
#include <tuple>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N,T,D;	//시작줄 인원, 인당 최대 업무시간, 지켜볼 시간
	cin >> N >> T >> D;
	queue<pair<int, int>> Q;
	// 줄서있는 사람들의 id와 업무량 저장
	for (int i{ 0 }; i < N; ++i)
	{
		int id, t;
		cin >> id >> t;
		Q.emplace(id, t);
	}

	//우선순위 큐도 가능?
	int M;	//더 올 사람들 인원.
	cin >> M;

	priority_queue< tuple<int, int, int>,vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > PQ;
	for (int i{ 0 }; i < M; ++i)
	{
		int id, t, w;	//w for time to add queue
		cin >> id >> t >> w;
		PQ.emplace(w, id, t);
	}

	pair<int, int> curr = { -1, 0 };
	int time_left{ T };

	for (int t{ 1 }; t <= D; ++t)
	{
		if (curr.first == -1)
		{
			curr = Q.front();
			time_left = T;
			Q.pop();
		}

		if(!PQ.empty() && (get<0>(PQ.top()) == t))
		{
			Q.emplace(get<1>(PQ.top()), get<2>(PQ.top()));
			PQ.pop();
		}

		if (curr.first != -1)
		{
			cout << curr.first << '\n';
			--curr.second;
			--time_left;
		}	

		if (curr.second == 0)
		{
			curr = { -1, 0 };
		}
		else if (time_left == 0)
		{
			Q.emplace(curr);
			curr = { -1, 0 };
		}
	}

	return 0;
}