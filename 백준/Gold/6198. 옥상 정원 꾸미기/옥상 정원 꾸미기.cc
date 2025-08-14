#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long sum;
int height[80005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> height[i];

    stack<pair<int, int>> S; // (높이, 해당 높이의 연속된 개수) 저장
    S.push({1000000001, 1}); // 더미 값 추가

    for (int i = n - 1; i >= 0; i--) {
        int count = 1; // 현재 높이의 개수 (초기값 1)

        while (height[i] > S.top().first) {
            sum += S.top().second; // pop되는 높이의 개수만큼 정답에 더함
            count += S.top().second; // 현재 높이와 같은 높이의 개수 누적
            S.pop();
        }

        S.push({height[i], count}); // 현재 높이와 개수를 스택에 저장
    }

    cout << sum;
    return 0;
}