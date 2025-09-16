#include <vector>
#include <tuple>

using namespace std;

int N;
int MAX_SHEEP{ 1 };


// mask first bit 1 -> root visited
void DFS(vector<tuple<int, int, int>>& vec, int index, int sheep, int wolf, int mask)
{
    if (get<0>(vec[index]))
    {
        ++wolf;
    }
    else
    {
        ++sheep;
    }

    if (wolf >= sheep)
        return;

    MAX_SHEEP = max(sheep, MAX_SHEEP);

    mask &= ~(1 << index);

    if (get<1>(vec[index]) != 0)
    {
        mask |= (1 << get<1>(vec[index]));
    }
    if (get<2>(vec[index]) != 0)
    {
        mask |= (1 << get<2>(vec[index]));
    }

    for (int i{ 0 }; i < N; ++i)
    {
        if (mask & (1 << i))
        {
            DFS(vec, i, sheep, wolf, mask);
        }
    }
}

//info-> sheep 0, wolf 1
int solution(vector<int> info, vector<vector<int>> edges) {

    N = info.size();
    //each node stats from root
    vector<tuple<int, int, int>> v(N);    //info, child, child    ->if child 0 => no child

    for (int i{ 0 }; i < N - 1; ++i)
    {
        get<0>(v[i]) = info[i];

        if (get<1>(v[edges[i][0]]) == 0)
        {
            get<1>(v[edges[i][0]]) = edges[i][1];
        }
        else if (get<2>(v[edges[i][0]]) == 0)
        {
            get<2>(v[edges[i][0]]) = edges[i][1];
        }
    }
    get<0>(v[N - 1]) = info.back();

    //(1 << get<1>(v[0])) | (1 << get<2>(v[0]))
    DFS(v, 0, 0, 0, 1);

    return MAX_SHEEP;
}