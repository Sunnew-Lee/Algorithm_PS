#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int arr[500001];

// 이진 탐색 함수
void bs(int& answer, const int& target, int start, int end )
{
	if (start >= end)
	{
		if (arr[start] == target)
			++answer;
		return;
	}
		

	int mid = (start + end) / 2;
	if (arr[mid] <= target)
	{
		if (arr[mid] == target)
			++answer;
		bs(answer, target, mid+1, end);
	}
	else
		bs(answer, target, start, mid);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int N, M, target;
	cin >> N;
	for (int i{ 0 }; i < N; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	cin >> M;
	unordered_map<int, int> m;
	for (int i{ 0 }; i < M; ++i)
	{
		cin >> target;

		if (m.find(target) == m.end())
		{
			int answer{ 0 };
			bs(answer, target, 0, N - 1);

			m.emplace(target, answer);
		}

		//cout << m[target] << ' ';
		cout << upper_bound(arr,arr+N,target) - lower_bound(arr, arr + N, target) << ' ';
	}


	return 0;
}