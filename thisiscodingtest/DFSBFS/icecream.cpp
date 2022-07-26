#include <iostream>
#include <vector>

using namespace std;

int ice[1000][1000];
//bool visited[1000][1000];
int N, M;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool isIn(int r, int c)
{
    if (0 <= r && r < N && 0 <= c && c < M)
    {
        return true;
    } 
    else
    {
        return false;
    }
};  

int DFS(int r, int c)
{
    if (ice[r][c] == 0)
    {
        ice[r][c] = 1; // visit
    } else
    {
        return 0; // already visit or blocked
    }

    // search
    for(int i = 0; i < 4; i++)
    {
        if (isIn(r + dr[i], c + dc[i]))
        {
            DFS(r + dr[i], c + dc[i]);
        }
    }

    return 1;
};

int main(void)
{
    int answer = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &ice[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (ice[i][j] == 0)
            {
                answer++;
                DFS(i, j);
            }
        }
    }
    cout << answer << endl;
    return 0;
}