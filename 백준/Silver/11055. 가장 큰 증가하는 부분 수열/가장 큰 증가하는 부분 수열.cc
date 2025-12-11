#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int D[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, num;
	cin >> N;
	
	for (int i{ 0 }; i < N; ++i)
	{
		cin >> arr[i];
	}

	for (int i{ 0 }; i < N; ++i)
	{
		D[i] = arr[i];
		for (int j{ 0 }; j < i; ++j)
		{
			if (arr[j] < arr[i])
			{
				D[i] = max(D[i], D[j] + arr[i]);
			}
		}
	}

	cout << *max_element(D, D + N + 1);
}