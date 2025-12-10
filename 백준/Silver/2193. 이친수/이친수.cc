#include <iostream>
using namespace std;

// 0, 1
pair<long long, long long> D[91];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	D[1] = { 0,1 };	// 1
	D[2] = { 1,0 };	// 10

	for (int i{ 3 }; i <= N; ++i)
	{
		D[i] = { D[i - 1].first + D[i - 1].second, D[i - 1].first };
	}
	
	cout << D[N].first + D[N].second;
}