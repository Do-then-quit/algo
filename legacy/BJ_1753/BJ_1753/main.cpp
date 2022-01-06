//
//  main.cpp
//  BJ_1753
//
//  Created by LeeMinkyo on 2021/02/06.
// 다익스트라를 이해하는것도 힘들었지만 priority_queue의 comp함수를 작성하는 방식이 달라서 어려웠다.
// 이참에 priorityqueue와 다익스트라를 연습하게 되었다~.

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

struct edge {
    int fromVertex;
    int toVertex;
    int weight;
    edge(int u, int v, int w) {
        fromVertex = u;
        toVertex = v;
        weight = w;
    }
};


struct vertex {
    int idx;
    bool isVisited = false;
    int shortestFromStart = 400000;
    vector<edge> adjEdges;
};


struct comp{
    bool operator()(vertex a, vertex b){
        return a.shortestFromStart > b.shortestFromStart;   //여기 방향이 너무 중요하다. 이거떄문에 거의 3시간 버렸다. sort에서 cmp작성과는 반대다!
    }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V, E;
    int startVertex;
    cin >> V >> E;
    cin >> startVertex;
    
    vertex vertexList[V+1];
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vertexList[u].adjEdges.push_back(edge(u, v, w));
    }
    for (int i = 1; i <= V; i++) {
        vertexList[i].idx = i;
    }
    
    vertexList[startVertex].shortestFromStart = 0;
    
    priority_queue<vertex, vector<vertex>, comp> pq;
    
    pq.push(vertexList[startVertex]);
    while (!pq.empty()) {
        int idx = pq.top().idx;
        vertex cur = vertexList[idx];
        pq.pop();
        if (vertexList[idx].isVisited == true) {
            continue;
        }
        
        for (int i = 0; i < cur.adjEdges.size(); i++) {
            int v = cur.adjEdges[i].toVertex;
            int w = cur.adjEdges[i].weight;
            
            if(vertexList[v].shortestFromStart > cur.shortestFromStart + w) {
                vertexList[v].shortestFromStart = cur.shortestFromStart + w;
                pq.push(vertexList[v]);
            }
        }
        vertexList[idx].isVisited = true;
    }
    
    for (int i = 1; i <= V; i++) {
        if (vertexList[i].shortestFromStart == 400000) {
            cout << "INF\n";
            continue;
        }
        cout << vertexList[i].shortestFromStart << "\n";
    }
    
    
    return 0;
}
