#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int i, j;
    int dist;
    bool isBreak;
};

int minDist = -1;

int main(void) {
    int arr[1001][1001];
    bool isVisited[1001][1001][2];   //3 == isBreak;
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++) {
            scanf("%1d", &(arr[i][j]));
            isVisited[i][j][0] = false;
            isVisited[i][j][1] = false;
        }
    }
    
    // bfs?
    queue<node> q;
    isVisited[1][1][0] = true;
    node temp;
    temp.i = 1; temp.j = 1; temp.dist = 1; temp.isBreak = false;
    q.push(temp);

    while(q.empty() == false) {
        node cur = q.front();
        q.pop();
        if(cur.i == N && cur.j == M) {
            minDist = cur.dist;
            break;
        }
        isVisited[cur.i][cur.j][cur.isBreak] = true;
        // up
        int next_i, next_j;
        next_i = cur.i - 1; next_j = cur.j;

        if(1 <= next_i && next_i <= N && 1 <= next_j && next_j <= M) {    
            if(arr[next_i][next_j] == 0 || cur.isBreak == false) {
                if(arr[next_i][next_j] == 0) {
                    if(isVisited[next_i][next_j][cur.isBreak] == false) {
                        if(next_i == N && next_j == M) {
                            minDist = cur.dist + 1;
                            break;
                        }
                        isVisited[next_i][next_j][cur.isBreak] = true;
                        node neigh;
                        neigh.i = next_i; neigh.j = next_j; neigh.dist = cur.dist + 1;
                        neigh.isBreak = cur.isBreak;
                        q.push(neigh);
                    }
                    
                } else {
                    if(isVisited[next_i][next_j][true] == false) {
                        if(next_i == N && next_j == M) {
                            minDist = cur.dist + 1;
                            break;
                        }
                        isVisited[next_i][next_j][true] = true;
                        node neigh;
                        neigh.i = next_i; neigh.j = next_j; neigh.dist = cur.dist + 1;
                        neigh.isBreak = true;
                        q.push(neigh);
                    }
                }
            }    
        }
        // down
        next_i = cur.i + 1; next_j = cur.j;

        if(1 <= next_i && next_i <= N && 1 <= next_j && next_j <= M) {    
            if(arr[next_i][next_j] == 0 || cur.isBreak == false) {
                if(arr[next_i][next_j] == 0) {
                    if(isVisited[next_i][next_j][cur.isBreak] == false) {
                        if(next_i == N && next_j == M) {
                            minDist = cur.dist + 1;
                            break;
                        }
                        isVisited[next_i][next_j][cur.isBreak] = true;
                        node neigh;
                        neigh.i = next_i; neigh.j = next_j; neigh.dist = cur.dist + 1;
                        neigh.isBreak = cur.isBreak;
                        q.push(neigh);
                    }
                    
                } else {
                    if(isVisited[next_i][next_j][true] == false) {
                        if(next_i == N && next_j == M) {
                            minDist = cur.dist + 1;
                            break;
                        }
                        isVisited[next_i][next_j][true] = true;
                        node neigh;
                        neigh.i = next_i; neigh.j = next_j; neigh.dist = cur.dist + 1;
                        neigh.isBreak = true;
                        q.push(neigh);
                    }
                }
            }    
        }
        // left
        next_i = cur.i; next_j = cur.j - 1;

        if(1 <= next_i && next_i <= N && 1 <= next_j && next_j <= M) {    
            if(arr[next_i][next_j] == 0 || cur.isBreak == false) {
                if(arr[next_i][next_j] == 0) {
                    if(isVisited[next_i][next_j][cur.isBreak] == false) {
                        if(next_i == N && next_j == M) {
                            minDist = cur.dist + 1;
                            break;
                        }
                        isVisited[next_i][next_j][cur.isBreak] = true;
                        node neigh;
                        neigh.i = next_i; neigh.j = next_j; neigh.dist = cur.dist + 1;
                        neigh.isBreak = cur.isBreak;
                        q.push(neigh);
                    }
                    
                } else {
                    if(isVisited[next_i][next_j][true] == false) {
                        if(next_i == N && next_j == M) {
                            minDist = cur.dist + 1;
                            break;
                        }
                        isVisited[next_i][next_j][true] = true;
                        node neigh;
                        neigh.i = next_i; neigh.j = next_j; neigh.dist = cur.dist + 1;
                        neigh.isBreak = true;
                        q.push(neigh);
                    }
                }
            }    
        }
        // right
        next_i = cur.i; next_j = cur.j + 1;

        if(1 <= next_i && next_i <= N && 1 <= next_j && next_j <= M) {    
            if(arr[next_i][next_j] == 0 || cur.isBreak == false) {
                if(arr[next_i][next_j] == 0) {
                    if(isVisited[next_i][next_j][cur.isBreak] == false) {
                        if(next_i == N && next_j == M) {
                            minDist = cur.dist + 1;
                            break;
                        }
                        isVisited[next_i][next_j][cur.isBreak] = true;
                        node neigh;
                        neigh.i = next_i; neigh.j = next_j; neigh.dist = cur.dist + 1;
                        neigh.isBreak = cur.isBreak;
                        q.push(neigh);
                    }
                    
                } else {
                    if(isVisited[next_i][next_j][true] == false) {
                        if(next_i == N && next_j == M) {
                            minDist = cur.dist + 1;
                            break;
                        }
                        isVisited[next_i][next_j][true] = true;
                        node neigh;
                        neigh.i = next_i; neigh.j = next_j; neigh.dist = cur.dist + 1;
                        neigh.isBreak = true;
                        q.push(neigh);
                    }
                }
            }    
        }
    }

    cout << minDist;


    return 0;
    
}