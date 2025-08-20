#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int size, k;
    cin >> size >> k;

    queue<int> q;
    for (int i{ 1 }; i <= size; i++)
    {
        q.push(i);
    }

    //auto temp = q.begin();
    cout << '<';
    while (q.size())
    {
        for (int i{ 1 }; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();

        if (q.empty())
        {
            cout << '>';
        }
        else
        {
            cout << ", ";
        }
    }

    return 0;
}