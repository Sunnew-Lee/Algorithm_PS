#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char arr[25];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int answer{ 0 };

    for (int i{ 0 }; i < 25; i++)
        cin >> arr[i];
    //25개 중 7개 뽑음 => 0000000 1111111111111111
    vector<int> v(7);
    v.resize(25, 1);


    do
    {
        int S{ 0 };
        vector<int> temp;
        for (int i{ 0 }; i < 25; i++)
        {
            if (v[i] == 1)
                continue;

            if (arr[i] == 'S')
                S++;

            temp.push_back(i);
        }

        if (S > 3)
        {
            bool isSelected[5][5] = { false, };
            for (int pos : temp)
            {
                int r = pos / 5; // 행
                int c = pos % 5; // 열
                isSelected[r][c] = true;
            }

            queue<pair<int, int>> q;
            bool visited[5][5] = { false, };
            int connected_count = 0;

            // 시작점 찾기 (조합의 첫 번째 요소)
            int start_pos = temp[0];
            int start_r = start_pos / 5;
            int start_c = start_pos % 5;

            q.push({ start_r, start_c });
            visited[start_r][start_c] = true;
            connected_count = 1;

            int dr[] = { -1, 1, 0, 0 };
            int dc[] = { 0, 0, -1, 1 };

            while (!q.empty()) {
                pair<int, int> current = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int nr = current.first + dr[i];
                    int nc = current.second + dc[i];

                    // 조건 1: 격자 범위 확인
                    if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;

                    // 조건 2 & 3: 선택된 자리이며, 아직 방문하지 않았는지 확인
                    if (isSelected[nr][nc] && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({ nr, nc });
                        connected_count++;
                    }
                }
            }

            if (connected_count == 7)
                answer++;
        }

    } while (next_permutation(v.begin(), v.end()));
    
    cout<<answer;
    
    return 0;
}