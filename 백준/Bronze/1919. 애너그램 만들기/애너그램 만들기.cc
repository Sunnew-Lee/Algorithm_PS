#include <iostream>
#include <cmath>
using namespace std;

int arr[26];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str1, str2;
    cin >> str1 >> str2;


    for (char c : str1)
    {
        arr[c - 'a']++;
    }
    for (char c : str2)
    {
        arr[c - 'a']--;
    }

    int answer{ 0 };
    for (int n : arr)
    {
        answer += abs(n);
    }

    cout << answer;

    return 0;
}