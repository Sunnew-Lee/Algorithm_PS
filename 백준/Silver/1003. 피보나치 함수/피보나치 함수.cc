#include <iostream>
using namespace std;

std::pair<long long, long long> arr[41];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N;
	cin >> T;

	arr[0] = { 1,0 };
	arr[1] = { 0,1 };
	for (int i{ 2 }; i < 41; ++i)
	{
		arr[i].first = arr[i - 2].first + arr[i - 1].first;
		arr[i].second = arr[i - 2].second + arr[i - 1].second;
	}

	while (T--)
	{
		cin >> N;
		cout << arr[N].first << ' ' << arr[N].second << '\n';
	}
}