#include <iostream>
//#include <string>

using namespace std;
char arr[64][64];
//string arr[64];

bool all_same(int N, pair<int, int> start)
{
    int row = start.first;
    int column = start.second;
    char temp = arr[row][column];

    for (int i{ 0 }; i < N; i++)
        for (int j{ 0 }; j < N; j++)
        {
            if (temp != arr[row + i][column + j])
                return false;
        }

    return true;
}

void func(int N, pair<int, int> start)
{
    if (all_same(N, start))
    {
        cout << arr[start.first][start.second];
    }
    else
    {
        cout << '(';
        int half = N / 2;

        for (int i{ 0 }; i < 4; i++)
        {
            func(half, { start.first + (i / 2) * half, start.second + (i % 2) * half });
        }
        cout << ')';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i{ 0 }; i < N; i++)
        for (int j{ 0 }; j < N; j++)
        {
            cin >> arr[i][j];
        }

    func(N, { 0,0 });



    return 0;
}