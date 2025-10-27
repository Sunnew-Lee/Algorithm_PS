#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s[301]; // Stair scores (1-based index)
int dp[301]; // DP table (1-based index)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    // Base Cases
    dp[0] = 0;
    dp[1] = s[1];
    if (n >= 2) { // Need to handle n=1 case
        dp[2] = s[1] + s[2];
    }

    // Fill DP table using the recurrence relation
    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i-3] + s[i-1] + s[i], dp[i-2] + s[i]);
    }

    // Final answer is the max score at the last stair
    cout << dp[n];

    return 0;
}