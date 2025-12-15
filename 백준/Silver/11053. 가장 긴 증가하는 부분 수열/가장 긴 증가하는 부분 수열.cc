#include <iostream>

using namespace std;

int arr[1000];
int D[1000];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, answer{ 0 };
	cin >> N;

	for (int i{ 0 }; i < N; ++i)
	{
		cin >> arr[i];
	}

	for (int i{ 0 }; i < N; ++i)
	{
		D[i] = 1;
		for (int j{ 0 }; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				D[i] = max(D[i], D[j] + 1);
			}
		}

		answer = max(answer, D[i]);
	}
	

	cout << answer;

	return 0;
}