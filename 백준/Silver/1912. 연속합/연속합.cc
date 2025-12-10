#include <iostream>
using namespace std;

int arr[100001];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, num, answer;
	cin >> n;

	cin >> arr[0];	// 현재 최대 합
	answer = arr[0];

	for (int i{ 1 }; i < n; ++i)
	{
		cin >> num;
		arr[i] = max(arr[i - 1] + num, num);

		answer = max(answer, arr[i]);
	}

	cout << answer;

}