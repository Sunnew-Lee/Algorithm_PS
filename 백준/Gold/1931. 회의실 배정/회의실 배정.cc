#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Meeting
{
    Meeting(){}
    Meeting(int s, int t) :start(s), end(t) {}
    int start{ 0 };
    int end{ 0 };
};

struct comp
{
    bool operator ()(Meeting& a, Meeting& b)
    {
        if (a.end == b.end)
        {
            return a.start > b.start;
        }
        return a.end > b.end;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<Meeting, vector<Meeting>, comp> PQ;
    while (N--)
    {
        int s, t;
        cin >> s >> t;
        PQ.push({ s,t });
    }

    Meeting select;
    int count{ 0 };
    while (!PQ.empty())
    {
        Meeting temp = PQ.top(); PQ.pop();
        if (select.end > temp.start)
        {
            continue;
        }
        select = temp;
        ++count;
    }
    cout << count;

    return 0;
}