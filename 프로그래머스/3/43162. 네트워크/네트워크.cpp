#include <string>
#include <vector>

using namespace std;

//즉 뭉치가 몇개냐?
//0부터 

void DFS(int idx, vector<bool>& vis, vector<vector<int>>& computers)
{
    //이미 방문했다면 돌아간다.
    if(vis[idx]==true)
    {
        return;
    }
    
    int N = vis.size();
    vis[idx] = true;
    
    for(int i{0};i<N;++i)
    {
        if(i==idx || computers[idx][i]==0)
            continue;
        
        DFS(i,vis,computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,false);
    

    for(int i{0};i<n;++i)
    {
        if(visited[i]==true)
        {
            continue;
        }
    
        DFS(i,visited,computers);
        ++answer;
    }
    
    
    return answer;
}