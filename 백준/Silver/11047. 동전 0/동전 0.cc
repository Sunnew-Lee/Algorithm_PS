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
        if (values[i] > K)
        {
            continue;
        }
        if (values[i] == K)
        {
            cout << ++count;
            break;
        }

        while (values[i] <= K)
        {
            K -= values[i];
            ++count;
        }

        if (K == 0)
        {
            cout << count;
            break;
        }
    }

    return 0;
}