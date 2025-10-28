#include <iostream>

using namespace std;
int dp[1001][3];
int value[1001][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i{ 1 }; i <= N; ++i)
    {
        cin >> value[i][0] >> value[i][1] >> value[i][2];
    }

    dp[1][0] = value[1][0];
    dp[1][1] = value[1][1];
    dp[1][2] = value[1][2];

    for (int i{ 2 }; i <= N; ++i)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + value[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + value[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + value[i][2];
    }
    
    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);

    return 0;
}