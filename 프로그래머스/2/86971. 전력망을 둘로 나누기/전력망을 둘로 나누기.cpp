#include <vector>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

int DFS(int N, int v1,int v2, vector<vector<int>>& graph)
{
    vector<bool> visited(N+1,false);
    //visited[0]=true;
    
    int count{0};
    
    stack<int> s;
    s.push(1);
    
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        
        visited[node]=true;
        //cout<<node<<',';
        ++count;
        
        int check{0};
        
        //else if check needed?
        if(node == v1)
        {
            check = v2;
            //cout<<"v2"<<':'<<v2;
        }
        else if(node == v2)
        {
            check = v1;
            //cout<<"v1"<<':'<<v1;
        }
        

        for(int n: graph[node])
        {
            if(visited[n] || n==check)
            {
                continue;
            }
            
            s.push(n);
        }
    }
    //cout<<'\n'<<count;
    return abs(2*count - N);
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    // 1.인접리스트로 그래프 구성
    vector<vector<int>> graph(n+1); // 0번 인덱스 버림. 0,1,2,3,4
    for(vector<int>& v : wires)
    {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    // 2.for each wire DFS
    for(vector<int>& v : wires)
    {
        answer = min(answer, DFS(n, v[0], v[1], graph));
    }
    
    
    return answer;
}