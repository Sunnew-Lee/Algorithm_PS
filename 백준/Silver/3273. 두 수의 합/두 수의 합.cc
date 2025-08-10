#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, target;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cin >> target;

    sort(arr, arr + n);

    int left = 0;      // 시작 인덱스
    int right = n - 1; // 끝 인덱스
    int result = 0;

    // left와 right가 교차하기 전까지 반복
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            result++;
            // 두 포인터를 모두 이동시켜 다음 쌍을 찾음
            left++;
            right--;
        }
        else if (sum < target) // 합이 작으면 left를 오른쪽으로 이동
        {
            left++;
        }
        else // sum > target, 합이 크면 right를 왼쪽으로 이동
        {
            right--;
        }
    }

    cout << result;

    return 0;
}