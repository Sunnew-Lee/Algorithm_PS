#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int size;
    cin >> size;
    string str, cmp;

    for (int i{ 0 }; i < size; i++)
    {
        int arr[26] = {};
        cin >> str >> cmp;
        for (char c : str)
        {
            arr[c - 'a']++;
        }
        for (char c : cmp)
        {
            arr[c - 'a']--;
        }

        int j{ 0 };
        while (j<26)
        {
            if (arr[j])
            {
                cout << "Impossible\n";
                break;
            }
            j++;
        }
        if(j==26)
            cout << "Possible\n";
    }

    return 0;
}