#include <iostream>
#include <vector>

using namespace std;

int main(void) 
{
    int ans = 0;
    int V, E;
    cin >> V >> E;
    vector<pair<int, int> > W[10001];
    
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        W[A].push_back(make_pair(B, C));
        W[B].push_back(make_pair(A, C));
    }
    // selected 를 선언해서 트리에 엣지들을 넣을수도 있다.
    // nearest를 활용하여 어떤 에지가 가까운지도 저장해놓으면 된다.
    // 정답을 더해나갈때 (added를 수정할때) 에지를 selected에 넣어주면된다.
    
    vector<bool> added(V+1, false);
    vector<int> distance(V+1, 1000001);
    //vector<int> nearest(V+1, -1);
    distance[1] = 0;
    //nearest[1] = 1;
    for (int iter = 0; iter < V; iter++)
    {
        int u = -1; // index
        for (int v = 1; v <= V; v++)
        {
            if (!added[v] && (u == -1 || distance[u] > distance[v]))
            {
                u = v;
            }
        }
        // 트리에 에지 추가 
        //
        ans += distance[u];
        added[u] = true;

        //distance update
        for (int i = 0; i < W[u].size(); i++)
        {
            int v = W[u][i].first;
            int weight = W[u][i].second;
            if (!added[v] && distance[v] > weight)
            {
                distance[v] = weight;
                //nearest[v] = u;
            }
            
        }
        
    }
    cout << ans;
    return 0;
     
}