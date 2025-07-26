#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int visited[101][101][2]; // [y][x][0]: 레버X, [y][x][1]: 레버O
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    pair<int, int> start;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == 'S') {
                start = {i, j};
                break;
            }
        }
    }

    memset(visited, -1, sizeof(visited));
    queue<tuple<int, int, int>> q;

    // 시작점: (y, x, 레버상태=0)
    q.push({start.first, start.second, 0});
    visited[start.first][start.second][0] = 0;

    while (!q.empty()) {
        auto [y, x, lever_on] = q.front();
        q.pop();

        // **종료 조건**
        if (maps[y][x] == 'E' && lever_on == 1) {
            return visited[y][x][1];
        }

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int next_lever_status = lever_on;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || maps[ny][nx] == 'X') {
                continue;
            }

            // **상태 전이 조건**
            if (maps[ny][nx] == 'L') {
                next_lever_status = 1; // 레버를 밟으면 다음 상태는 무조건 1
            }

            // **방문 확인 조건**
            if (visited[ny][nx][next_lever_status] == -1) {
                visited[ny][nx][next_lever_status] = visited[y][x][lever_on] + 1;
                q.push({ny, nx, next_lever_status});
            }
        }
    }

    return -1;
}