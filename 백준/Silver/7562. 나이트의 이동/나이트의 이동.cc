#include <iostream>
#include <queue>
using namespace std;

int arr[300][300];
struct point
{
    point() {};
    point(int x, int y) :X(x), Y(y) {};

    bool operator==(point& other) const 
    {
        return X == other.X && Y == other.Y;
    }

    int X{ 0 }, Y{ 0 };

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    point dir[8] = { {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };    //오른아래부터 시계방향
    int scenarios, N;
    cin >> scenarios;

    point start, end;
    while (scenarios--)
    {
        cin >> N >> start.X >> start.Y >> end.X >> end.Y;
        //arr[start.Y][start.X] = 0;
        queue<point> Q;
        Q.push(start);

        while (!Q.empty())
        {
            point temp = Q.front();
            if (temp == end)
            {
                cout << arr[temp.Y][temp.X] << '\n';
                break;
            }

            Q.pop();

            for (int i{ 0 }; i < 8; i++)
            {
                int nx = temp.X + dir[i].X;
                int ny = temp.Y + dir[i].Y;

                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;

                if (arr[ny][nx] == 0)
                {
                    Q.push({ nx,ny });
                    arr[ny][nx] = arr[temp.Y][temp.X] + 1;
                }
            }
        }

        fill(&arr[0][0], &arr[N][0], 0);

    }



    return 0;
}