//
//  main.cpp
//  BJ_1865
//
//  Created by LeeMinkyo on 2021/02/09.
//  이게 왜될까... 벨만포드...너란녀석...

#include <iostream>
#include <limits.h>

using namespace std;

struct edge {
    int firstVertex;
    int secondVertex;
    int time;
};

struct wormhole {
    int startVertex;
    int endVertex;
    int time;
};

edge E[2500];
wormhole H[200];


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    
    for (int i = 0; i < TC; i++) {
        int N, M, W;
        cin >> N >> M >> W;
        int dist[N+1];
        
        for (int j = 0; j < M; j++) {
            cin >> E[j].firstVertex >> E[j].secondVertex >> E[j].time;
        }
        for (int j = 0; j < W; j++) {
            int temp;
            cin >> H[j].startVertex >> H[j].endVertex >> temp;
            H[j].time = -temp;
        }
        bool checkCycle = false;
        
        for (int k = 1; k <= N; k++) {
            dist[k] = INT_MAX - 10000;
        }
        
        for (int round = 0; round < N; round++) {
            for (int edgeCur = 0; edgeCur < M; edgeCur++) {
                if (dist[E[edgeCur].secondVertex] > dist[E[edgeCur].firstVertex] + E[edgeCur].time) {
                    dist[E[edgeCur].secondVertex] = dist[E[edgeCur].firstVertex] + E[edgeCur].time;
                    if (round == N - 1) {
                        checkCycle = true;
                        break;
                    }
                }
                if (dist[E[edgeCur].firstVertex] > dist[E[edgeCur].secondVertex] + E[edgeCur].time) {
                    dist[E[edgeCur].firstVertex] = dist[E[edgeCur].secondVertex] + E[edgeCur].time;
                    if (round == N - 1) {
                        checkCycle = true;
                        break;
                    }
                }
            }
            for (int holeCur = 0; holeCur < W; holeCur++) {
                if (dist[H[holeCur].endVertex] > dist[H[holeCur].startVertex] + H[holeCur].time) {
                    dist[H[holeCur].endVertex] = dist[H[holeCur].startVertex] + H[holeCur].time;
                    if (round == N - 1) {
                        checkCycle = true;
                        break;
                    }
                }
            }
        }
        if (checkCycle == true) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    
    
    return 0;
}
