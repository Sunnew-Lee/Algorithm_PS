#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size, num;
    cin >> size;
    stack<int> stk;
    string str;

    int i{ 1 };
    while (size--)
    {
        cin >> num;
        while (i <= num)
        {
            str += "+\n";
            stk.push(i++);
        }
        if (stk.top() == num)
        {
            stk.pop();
            str += "-\n";
        }
        else
        {
            cout << "NO";
            return 0;
        }

    }

    cout << str;
    

    return 0;
}