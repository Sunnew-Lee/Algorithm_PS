#include <iostream>
#include <set>


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int T, k;
    cin >> T;

    while (T--)
    {
        cin >> k;
        multiset<int> ms;
        int num;
        char c;

        while (k--)
        {
            cin >> c >> num;
            if (c == 'I')
            {
                ms.insert(num);
            }
            else if (c == 'D')
            {
                if (ms.empty())
                    continue;

                if (num == 1)   //if(num)
                {
                    ms.erase(prev(ms.end()));
                }
                else
                    ms.erase(ms.begin());
            }
        }
        if (ms.empty())
        {
            cout << "EMPTY\n";
            continue;
        }

        cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }


    return 0;
}