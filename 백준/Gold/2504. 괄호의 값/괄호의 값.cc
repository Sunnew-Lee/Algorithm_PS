#include <iostream>
#include <string>
#include <stack>

using namespace std;

int arr[15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string str;
    cin >> str;

    int size = str.size();
    if (size == 1 || str[0] == ')' || str[0] == ']')
    {
        cout << 0;
        return 0;
    }

    stack<char> S;

    int sum = 0;
    int mul = 1;
    
    for (int i{ 0 }; i < size; ++i)
    {
        char& c = str[i];

        if (c == '(')
        {
            mul *= 2;
            S.push(c);
        }
        else if (c == '[')
        {
            mul *= 3;
            S.push(c);
        }

        if (c == ')')
        {
            if (S.empty() || S.top() == '[')
            {
                cout << 0;
                return 0;
            }
            if (str[i-1] == '(')
            {
                sum += mul;
            }
            mul /= 2;
            S.pop();
        }
        else if (c == ']')
        {
            if (S.empty() || S.top() == '(')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[')
            {
                sum += mul;
            }
            mul /= 3;
            S.pop();
        }
    }


    if (!S.empty())
        cout << 0;
    else
        cout << sum;

    return 0;
}