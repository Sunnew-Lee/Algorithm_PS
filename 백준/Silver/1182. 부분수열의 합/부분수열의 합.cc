#include <iostream>
using namespace std;

int arr[20];
int N, S, cnt;

void func(int cur, int height)
{
    if (height == N)
    {
        if(cur == S)
            cnt++;

        return;
    }

    func(cur + arr[height], height + 1);
    func(cur, height + 1);
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;

    int temp;
    for (int i{ 0 }; i < N; i++)
    {
        cin >> arr[i];
    }

    func(0, 0);
    if (S == 0)
        cnt--;
    
    cout << cnt;
    return 0;
}