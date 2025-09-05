//#include <iostream>
//#include <set>
//
//
//using namespace std;
//
//pair<int, int> jewellery[300001]; //Mass_i, Value_i
//int bags[300001];   //max mass hold
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(nullptr);
//
//    int N, K;
//    cin >> N >> K;
//    for (int i{ 0 }; i < N; ++i)
//    {
//        cin >> jewellery[i].first >> jewellery[i].second;
//    }
//    
//    for (int i{ 0 }; i < K; ++i)
//    {
//        cin >> bags[i];
//    }
//
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <unordered_map>    //문제번호
#include <set>  //

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    unordered_map<int, int> m;  //번호 난이도
    multiset<pair<int, int>> s;  //난이도 번호
    int N,M;
    cin >> N;
    while (N--)
    {
        int P, L;
        cin >> P >> L;
        m.emplace(P, L);
        s.emplace(L, P);
    }


    cin >> M;
    while (M--)
    {
        string str;
        int num1, num2;
        cin >> str >> num1;

        if (str == "add")
        {
            cin >> num2;
            m.emplace(num1, num2);
            s.emplace(num2, num1);

        }
        else if (str == "recommend")
        {
            if (num1==1)//1인 경우 추천 문제 리스트에서 가장 어려운 문제의 번호를/ 만약 가장 어려운 문제가 여러 개라면 문제 번호가 큰 것으로 출력
            {
                cout << (*prev(s.end())).second<<'\n';
            }
            else if(num1==-1)//추천 문제 리스트에서 가장 쉬운 문제의 번호를 출력
            {
                cout << (*s.begin()).second<<'\n';
            }
        }
        else if (str == "solved")
        {
            s.erase({ m[num1], num1 });
            m.erase(num1);
        }
    }

    return 0;
}