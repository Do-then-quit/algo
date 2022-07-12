#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph;
    graph.reserve(N + 1);
    vector<int> inDegree;
    inDegree.reserve(N+1);
    vector<bool> visited;
    visited.reserve(N + 1);

    fill(visited.begin(), visited.end(), false);
    fill(inDegree.begin(), inDegree.end(), 0);
    
    for (int i = 0; i < M; i++)
    {
        int singers;
        cin >> singers;

        int before = -1;
        for (int j = 0; j < singers; j++)
        {
            int cur;
            cin >> cur;
            if (before != -1) {
                //before->cur edge
                graph[before].push_back(cur);
                // in_degree?
                inDegree[cur]++;
            }

            before = cur;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0)
        {
            //queue insert, break, visited
            q.push(i);
            visited[i] = true;
        }
    }
    vector<int> answer;
    while (!q.empty())
    {
        int cur = q.front();
        //cout << cur << endl;
        q.pop();
        answer.push_back(cur);

        for(auto edge : graph[cur])
        {
            if (visited[edge] == false)
            {
                inDegree[edge]--;
                if (inDegree[edge] == 0)
                {
                    visited[edge] = true;
                    q.push(edge);
                }
            }
        }
    }

    if (answer.size() != N)
    {
        cout << 0 << endl;
        return 0;
    }

    for (auto n : answer)
    {
        cout << n << endl;
    }

    return 0;
}
