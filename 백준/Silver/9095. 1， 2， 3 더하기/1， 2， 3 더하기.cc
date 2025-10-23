#include <iostream>

using namespace std;
int D[12];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int T;
    cin >> T;

    D[0] = 1;
    D[1] = 1;
    D[2] = 2;
    for (int i{ 3 }; i <= 11; ++i)
    {
        D[i] = D[i - 1] + D[i - 2] + D[i - 3];
    }
    
    while (T--)
    {
        int N;
        cin >> N;
        cout << D[N]<<'\n';
    }
    

    return 0;
}