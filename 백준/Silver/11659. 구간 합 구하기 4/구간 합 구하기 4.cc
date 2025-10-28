#include <iostream>
using namespace std;

int pre[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, temp;
    cin >> N >> M;
    for (int i{ 0 }; i < N; i++)
    {
        cin >> temp;
        pre[i + 1] = pre[i] + temp;
    }

    while (M--)
    {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a-1] << '\n';
    }

    return 0;
}