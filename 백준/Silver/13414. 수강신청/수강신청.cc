#include <iostream>
#include <unordered_map>
#include <queue>
#include <iomanip>

using namespace std;

int arr[500001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, L, id;
    cin >> K >> L;

    unordered_map<int, int> m;  //id - index
    
    for (int i{ 0 }; i < L; ++i)
    {
        cin >> id;
        m[id] = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        pq.push({ (*it).second, (*it).first }); //index - id
    }

    cout.width(8);
    cout.fill('0');
    while (K-- && !pq.empty())
    {
        cout << setfill('0') << setw(8) << pq.top().second << '\n';
        pq.pop();
    }

    return 0;
}