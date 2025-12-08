#include <iostream>
#include <algorithm>
using namespace std;

int arr[502][502];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int row, num;
	cin >> row;

	cin >> arr[1][1];
	for (int i{ 2 }; i <= row; ++i)
	{
		for (int j{ 1 }; j <= i; ++j)
		{
			cin>> num;

			if (j == 1 || j==i)
			{
				if (j == 1)
				{
					arr[i][j] = arr[i - 1][1] + num;
				}
				else
				{
					arr[i][j] = arr[i - 1][j - 1] + num;
				}
				continue;
			}

			// 아니면 좌 우 부모중에 큰놈 + num을 저장
			int MAX = max(arr[i - 1][j - 1], arr[i - 1][j]);
			arr[i][j] = MAX + num;
		}
	}

	cout << *(max_element(arr[row] + 1, arr[row] + row + 1));

}