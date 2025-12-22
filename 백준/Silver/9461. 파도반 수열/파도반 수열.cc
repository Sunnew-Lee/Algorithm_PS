#include <iostream>
#include <algorithm>

using namespace std;

//int arr[1001];
long long D[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N;
	cin >> T;

	D[1] = 1;
	D[2] = 1;
	D[3] = 1;

	for (int i{ 4 }; i <= 100; ++i)
	{
		D[i] = D[i - 3] + D[i - 2];
	}

	while (T--)
	{
		cin >> N;
		cout << D[N] << '\n';
	}

}