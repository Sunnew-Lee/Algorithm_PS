#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    set<string> s;
    int n;
    cin >> n;

    while (n--)
    {
        string name, op;
        cin >> name >> op;

        if (op == "enter")
        {
            s.insert(name);
        }
        else if (op == "leave")
        {
            s.erase(name);
        }
    }

    for (auto it = s.rbegin();it!=s.rend();++it)
    {
        cout << *it << '\n';
    }


    return 0;
}