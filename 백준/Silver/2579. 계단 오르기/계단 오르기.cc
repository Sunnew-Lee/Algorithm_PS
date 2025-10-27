#include <iostream>

using namespace std;
int D1[305];    // 연속계단 1개째 -> 직전 계단은 건너뛰었다는 뜻.
int D2[305];    // 연속계단 2개째 -> 직전 계단은 반드시 밟음.
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

    D1[0] = 0;
    D1[1] = value[1];   // 처음에 한칸 뜀
    D1[2] = value[2];   // 처음에 두칸 뜀

    D2[0] = 0;
    D2[1] = 0;
    D2[2] = value[1]+ value[2]; // 한 계단씩 올라옴.

    for (int i{ 3 }; i <= 300; ++i)
    {

        D1[i] = max(D2[i - 2], D1[i - 2]) + value[i];
        D2[i] = D1[i - 1] + value[i];   // 연속계단 2개째의 전계단은 연속계단 1개째니까 D1!
    }
    
    cout << max(D1[N],D2[N]);
    

    return 0;
}