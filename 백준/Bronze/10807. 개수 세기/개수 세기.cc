#include <iostream>
using namespace std;

int arr[201];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int size, num;
    cin >> size;

    for (int i{ 0 }; i < size; i++)
    {
        cin >> num;
        arr[100+num]++;
    }

    cin >> num;
    cout << arr[num+100];
    return 0;
}