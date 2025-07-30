#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

bool bs(const int& target, int start, int end)
{
	if (end - start < 0)
		return false;

	int mid = (end - start) / 2;

	if (target == arr[mid])
		return true;
	if (target < arr[mid])
	{
		return bs(target, start, mid - 1);
	}
	return bs(target, mid + 1, end);	
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
	for (int i{ 0 }; i < M; ++i)
	{
		cin >> target;
		//cout << bs(target, 0, N - 1) << '\n';
		cout<<binary_search(arr, arr + N, target)<<'\n';
	}

	return 0;
}