#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int DFS(int N, vector<vector<int>>& graph)
{
    vector<bool> visited(N+1,false);
    int count{0};
    
    stack<int> s;
    s.push(1);
    
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        
        visited[node]=true;
        ++count;               

        for(int n: graph[node])
        {
            if(visited[n])
            {
                continue;
            }
            
            s.push(n);
        }
    }
    return abs(2*count - N);    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    // 1.for each wire
    for(vector<int>& skip_wire : wires)
    {
        // 2.인접리스트로 그래프 구성.
        vector<vector<int>> graph(n+1); // 0번 인덱스 버림. 0,1,2,3,4
        for(vector<int>& v : wires)
        {
            if(v[0] == skip_wire[0] && v[1] == skip_wire[1])
            {
                continue;
            }
            
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        
        //3.DFS
        answer = min(answer, DFS(n, graph));
    }
    
    
    return answer;
}