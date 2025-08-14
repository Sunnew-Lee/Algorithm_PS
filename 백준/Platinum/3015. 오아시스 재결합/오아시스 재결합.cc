#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size, num;
    long long sum{ 0 };
    cin >> size;
    stack<pair<int, int>> S;    // Stack에서 pop되는 애들은 더이상 짝을 만들 수 없는 애들. 들어있는 애들은 짝 만들 potential 있는 애들.

    while (size--)    //get input 
    {
        cin >> num;
        int count{ 1 };// Count of people with the same height

        while (!S.empty() && S.top().first <= num)  // num이 들어올 때
        {
            sum += S.top().second;  // 현재 Stack top이 볼 수 있는 짝 수를 더한다.

            if (S.top().first == num)
                count+= S.top().second; // Merge counts for same height

            S.pop();
        }        

        if (!S.empty())
            sum++;  // 자기 옆은 무조건 볼 수 있다.

        S.push({ num,count });
        
    }

    cout << sum;

    return 0;
}
