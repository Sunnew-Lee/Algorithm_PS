#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int N, num;
    cin >> N;

    priority_queue<int, vector<int>, cmp> PQ;

    for (int i{ 0 }; i < N * N; ++i)
    {
        int tmp;
        cin >> tmp;

        if (PQ.size() == N)
        {
            if (tmp > PQ.top())
            {
                PQ.pop();
                PQ.push(tmp);
            }

            continue;
        }

        PQ.push(tmp);
        
    }


    cout << PQ.top();

    return 0;
}