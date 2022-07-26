//bfs
#include <iostream>
#include <queue>

using namespace std;
int maze[201][201];
bool visited[201][201];
int N, M;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool isIn(int r, int c)
{
    if (1 <= r && r <= N && 1 <= c && c <= M)
    {
        if (maze[r][c] == 1)
        {
            return true;
        }
        return false;
    } 
    else
    {
        return false;
    }
};  

int main(void)
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &maze[i][j]);
        }
    }

    //bfs

    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    visited[1][1] = true;
    int level = 1;
    int curLevelSize = 1;

    while(!q.empty())
    {
        curLevelSize = q.size();
        for(int i = 0; i < curLevelSize; i++)
        {
            // search push
            int r = q.front().first;
            int c = q.front().second;
            //visited[r][c] = true;

            if (r == N && c == M)
            {
                cout << level << endl;
                return 0;
            }

            for(int j = 0; j < 4; j++)
            {
                //isIn, notvisited push, visited check
                int nextR = r + dr[j];
                int nextC = c + dc[j];
                if (isIn(nextR, nextC))
                {
                    if (!visited[nextR][nextC])
                    {
                        q.push(make_pair(nextR, nextC));
                        // q.push({nextR, nextC});  it works also probably
                        visited[nextR][nextC] = true;
                    }
                }
            }
            q.pop();

            //pop
        }
        level++;
        //level
    }
    cout << -1 << endl;
    return 0;
}