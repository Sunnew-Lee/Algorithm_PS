#include <iostream>
#include <queue>

using namespace std;

class cmp
{
public:
    bool operator() (int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
            
        return abs(a) > abs(b);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int N, num;
    cin >> N;

    priority_queue<int, vector<int>, cmp> PQ;
    while (N--)
    {
        cin >> num;

        if (num == 0)
        {
            //print + erase
            if (PQ.empty())
            {
                cout << 0 << '\n';
                continue;
            }

            cout << PQ.top() << '\n';
            PQ.pop();
            continue;
        }

        PQ.push(num);
    }
    

    return 0;
}