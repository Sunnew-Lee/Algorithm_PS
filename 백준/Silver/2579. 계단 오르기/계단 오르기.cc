#include <iostream>

using namespace std;
int dp[305];
int value[305];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i{ 1 }; i <= N; ++i)
    {
        cin >> value[i];
    }

    dp[0] = 0;
    dp[1] = value[1];
    dp[2] = value[1] + value[2];

    for (int i{ 3 }; i <= N; ++i)
    {
        // i-1 밟았을 때 -> path: i-3, i-1, i.
        //dp[i] = dp[i - 3] + value[i - 1] + value[i];

        // i-2 밟았을 때 -> path: i-2, i.
        //dp[i] = dp[i - 2] + value[i];

        dp[i] = max(dp[i - 3] + value[i - 1], dp[i - 2]) + value[i];
    }

    
    cout << dp[N];
    

    return 0;
}