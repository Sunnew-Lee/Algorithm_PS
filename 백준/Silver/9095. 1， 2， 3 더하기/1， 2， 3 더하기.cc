#include <iostream>

using namespace std;
int dp[12];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, num;
    cin >> N;
    dp[1] = 1; dp[2] = 2; dp[3] = 4;

    for (int i{ 4 }; i < 12; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while (N--)
    {
        cin >> num;
        cout << dp[num] << '\n';
    }

    return 0;
}

// 1
// 
// 1+1
// 2
//
// 1+1+1 2+1 1+2 3
// 
// 1+1+1+1 2+1+1 1+2+1 1+1+2 1+3 3+1