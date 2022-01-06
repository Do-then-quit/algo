//
//  main.cpp
//  BJ_11725
//
//  Created by LeeMinkyo on 2021/01/28.
//

#include <iostream>
#include <set>
#include <queue>
using namespace std;
struct Vertex {
    set<int> adj_v;
    int parent = 0;
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    Vertex v[N+1];
    
    for (int i = 0; i < N - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].adj_v.insert(v2);
        v[v2].adj_v.insert(v1);
    }
    
    queue<int> q;
    q.push(1);
    while (q.size() != 0) {
        int now = q.front();
        q.pop();
        set<int>::iterator it;
        for (it = v[now].adj_v.begin(); it != v[now].adj_v.end(); it++) {
            q.push(*it);
            v[*it].parent = now;
            v[*it].adj_v.erase(now);    //adj_v에서 부모를 삭제하지말고, visited배열을 운영하는것도 방법이다.
        }
    }
    for (int i = 2; i <= N; i++) {
        cout << v[i].parent << "\n";
    }
    
    
    return 0;
}
