#include <iostream>

using namespace std;
int dp[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int X;
    cin >> X;
    //dp[0]=0;

    for (int i{ 2 }; i <= X; i++)
    {
        //dp[i] = min(min(dp[i / 3], dp[i / 2]), dp[i + 1]) + 1;
        dp[i]= dp[i - 1] + 1;
        
        if (i % 3 == 0)
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        if (i % 2 == 0)
            dp[i] = min(dp[i / 2] + 1, dp[i]);            
    }

    cout << dp[X];
    return 0;
}