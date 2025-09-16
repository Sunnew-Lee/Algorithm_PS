#include <vector>
#include <queue>
using namespace std;

pair<int,int> dir[4] = { {1,0},{0,1},{-1,0},{0,-1} }; //x,y
int n,m;

bool BFS(vector< vector<int> >& map)
{
    queue<pair<int,int>> Q;
    Q.push({0,0});  //x,y
    
    while(!Q.empty())
    {
        pair<int,int> temp = Q.front();
        int x = temp.first;
        int y = temp.second;
        
        if(x == m-1 && y == n-1)
        {
            return true;
        }
        Q.pop();
        
        //check 4 dir
        for(int i{0};i<4;++i)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            
            if(nx<0 || nx >= m || ny<0 || ny>=n)
                continue;
            if(nx==0 && ny==0)
                continue;
            
            if(map[ny][nx] == 1)
            {
                map[ny][nx] = map[y][x] + 1;
                Q.push({nx,ny});
            }
        }
        
    }
    
    return false;
}

int solution(vector< vector<int> > maps)
{
    n = maps.size();    //row
    m = maps[0].size(); //column
    
    if(BFS(maps))
    {
        return maps[n-1][m-1];
    }
    
    return -1;
}