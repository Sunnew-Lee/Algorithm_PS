#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> DQ;
    int size, op, num, sum{ 0 };
    cin >> size >> op;

    for (int i{ 1 }; i <= size; i++)
        DQ.push_back(i);

    while (op--)
    {
        int count{ 0 };
        cin >> num;
        while (DQ.front() != num)
        {
            int temp = DQ.front();
            DQ.push_back(temp);
            DQ.pop_front();
            count++;
        }
        DQ.pop_front(); 
        //cout << count << '\n';
        if (count > size / 2)
            count = size - count;
        size--;
        //cout << count << '\n';
        sum += count;
    }

    cout << sum;

    return 0;
}