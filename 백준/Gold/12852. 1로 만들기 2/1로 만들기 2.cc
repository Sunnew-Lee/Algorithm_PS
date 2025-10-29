#include <iostream>
#include <queue>

using namespace std;
int dp[1000001];
int visited[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);


    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 0;

    for (int i{ 2 }; i <= N; ++i)
    {
        dp[i] = dp[i - 1];
        visited[i] = i - 1;

        if (i % 3 == 0)
        {
            if (dp[i / 3] < dp[i])
            {
                dp[i] = dp[i / 3];
                visited[i] = i / 3;
            }
        }

        if (i % 2 == 0)
        {
            if (dp[i / 2] < dp[i])
            {
                dp[i] = dp[i / 2];
                visited[i] = i / 2;
            }
        }

        ++dp[i];
    }

    cout << dp[N] << '\n';
    while (visited[N] != 0)
    {
        cout << N << ' ';
        N = visited[N];
    }
    cout << N;

    return 0;
}