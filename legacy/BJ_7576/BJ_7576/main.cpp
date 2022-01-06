//
//  main.cpp
//  BJ_7576
//
//  Created by LeeMinkyo on 2021/01/20.
//  pair를 써보았다! make_pair를 하면 구조체 만드는 것보다 편하다! 2개까지는...
// bfs가 이제 손에 좀 익는듯?

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int box[1000][1000];
int M, N;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue<pair<int, int>> q;
    
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 1) {
                q.push(make_pair(i, j));    //p.first = i, p.second = j;
            }
        }
    }
    int time = -1;
    while (q.empty() != true) {
        int Size = int(q.size());
        for (int i = 0; i < Size; i++) {
            //q에 있는만큼 팝, bfs.
            pair<int, int> p;
            p = q.front();
            q.pop();
            
            if (p.first - 1 >= 0 && box[p.first - 1][p.second] == 0) {
                q.push(make_pair(p.first - 1, p.second));
                box[p.first - 1][p.second] = 1;
            }
            if (p.first + 1 < N && box[p.first + 1][p.second] == 0) {
                q.push(make_pair(p.first + 1, p.second));
                box[p.first + 1][p.second] = 1;
            }
            if (p.second - 1 >= 0 && box[p.first][p.second - 1] == 0) {
                q.push(make_pair(p.first, p.second - 1));
                box[p.first][p.second - 1] = 1;
            }
            if (p.second + 1 < M && box[p.first][p.second + 1] == 0) {
                q.push(make_pair(p.first, p.second + 1));
                box[p.first][p.second + 1] = 1;
            }
        }
        time++;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    
    cout << time << "\n";
    
    return 0;
}
