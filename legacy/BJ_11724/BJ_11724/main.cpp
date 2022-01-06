//
//  main.cpp
//  BJ_11724
//
//  Created by LeeMinkyo on 2021/01/16.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
//this time, bfs

struct vertex {
    vector<int> adj_v;
};
vertex V[1001];
bool visited[1001] = {false,};

void dfs(int v) {
    visited[v] = true;
    queue<int> q;
    q.push(v);
    while (q.empty() != true) {
        v = q.front();
        q.pop();
        vector<int>::iterator ptr;
        for (ptr = V[v].adj_v.begin(); ptr != V[v].adj_v.end(); ++ptr) {
            if (!visited[*ptr]) {
                q.push(*ptr);
                visited[*ptr] = true;
            }
        }
    }
}

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        V[u].adj_v.push_back(v);
        V[v].adj_v.push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
