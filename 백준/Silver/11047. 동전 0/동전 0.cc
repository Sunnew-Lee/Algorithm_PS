#include <iostream>
#include <vector>

using namespace std;

int move;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<int> values(N);
    for (int i{ 0 }; i < N; ++i)
    {
        cin >> values[i];
    }

    int count{ 0 };
    for (int i{ N - 1 }; i >= 0; --i)
    {
        count += K / values[i];
        K %= values[i];
    }
    cout << count;

    return 0;
}