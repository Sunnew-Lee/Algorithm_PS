#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

//0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽
int N, M;
char arr[1002][1002];
int dist[1002][1002][2];

pair<int, int> dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };    //상 우 하 좌 y,x

void set_arr()
{
    char c;
    for (int i{ 1 }; i <= N; ++i)
    {
        for (int j{ 1 }; j <= M; ++j)
        {
            cin >> c;
            arr[i][j] = c;
        }
    }
}

//마지막 칸은 기회 한번 썼는지 안썼는지 판단용

int bfs()
{
    queue<tuple<int, int, int>> Q;

    if (arr[1][1] == '1')
    {
        dist[1][1][1] = 1;
        Q.push({ 1,1,1 });
    }
    else
    {
        dist[1][1][0] = 1;
        Q.push({ 1,1,0 });
    }
    //dist[N][M][0] = -1;
    //dist[N][M][1] = -1;


    //while문 끝내는 로직 넣기

    while (!Q.empty())
    {
        int y, x, broken;
        std::tie(y, x, broken) = Q.front();
        if (y == N && x == M)
            return dist[y][x][broken];
        Q.pop();


        for (int i{ 0 }; i < 4; ++i)
        {
            int ny = y + dir[i].first;
            int nx = x + dir[i].second;

            //if (dist[ny][nx] != 0 || arr[ny][nx] != '0')
            //    continue;

            //dist[ny][nx] = dist[temp.first][temp.second] + 1;
            //QQ.push({ ny,nx });

            //if (broken && arr[ny][nx] == '1')   // 한번 부순놈은 또 못 부순다
            //    continue;
            //if (dist[ny][nx][0] != 0 && dist[y][x][1] + 1 > dist[ny][nx][0]) // 이미 안부순놈이 지나간 길인데 부순놈이 더 느리면 거른다
            //    continue;

            //if (!broken && arr[ny][nx] == '1')
            //{
            //    dist[ny][nx][1] = dist[y][x][0] + 1;
            //    Q.push({ ny,nx,1 });
            //}
            //if (!broken && arr[ny][nx] == '0')
            //{
            //    dist[ny][nx][0] = dist[y][x][0] + 1;
            //    Q.push({ ny,nx,0 });
            //}
            //if (broken && arr[ny][nx] == '0' && dist[ny][nx][1] == 0)
            //{
            //    dist[ny][nx][1] = dist[y][x][1] + 1;
            //    Q.push({ ny,nx,1 });
            //}
            if (arr[ny][nx] == '0' && dist[ny][nx][broken] == 0)
            {
                dist[ny][nx][broken] = dist[y][x][broken] + 1;
                Q.push({ ny, nx, broken });
            }
            // (nx, ny)를 부수는 경우
            if (!broken && arr[ny][nx] == '1' && dist[ny][nx][1] == 0)
            {
                dist[ny][nx][1] = dist[y][x][broken] + 1;
                Q.push({ ny, nx, 1 });
            }

        }

    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;
    set_arr();

    cout << bfs();

    return 0;
}