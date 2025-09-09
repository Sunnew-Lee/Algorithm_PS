#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int N, num;
    cin >> N;

    vector<int> v(N, 0);
    for (int i{ 0 }; i < N; ++i)
    {
        cin >> v[i];
    }

    make_heap(v.begin(), v.end(), greater<int>());
    int sum{ 0 };

    while (v.size()>1)
    {
        int first, second;

        first = v[0];
        pop_heap(v.begin(), v.end(), greater<int>());
        v.pop_back();

        second = v[0];
        pop_heap(v.begin(), v.end(), greater<int>());
        v.pop_back();

        sum += first + second;

        v.push_back(first + second);
        push_heap(v.begin(), v.end(), greater<int>());
    }

    cout << sum;

    return 0;
}