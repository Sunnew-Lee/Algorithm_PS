#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;
    cin.ignore();

    vector<int> vec;
    string a;
    getline(cin, a);

    int num = 0;
    bool negative = false;

    for (char c : a) {
        if (c == ' ') {
            if (negative) {
                vec.push_back(-num);
            } else {
                vec.push_back(num);
            }
            num = 0;
            negative = false;
        } else if (c == '-') {
            negative = true;
        } else {
            num = num * 10 + (c - '0');
        }
    }
    if (negative) {
        vec.push_back(-num);
    } else {
        vec.push_back(num);
    }

    deque<int> dq;
    string result; // 결과를 저장할 문자열

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() < i - l + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && vec[dq.back()] > vec[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
        result += to_string(vec[dq.front()]) + " "; // 결과를 문자열에 추가
    }

    cout << result;

    return 0;
}