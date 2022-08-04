#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
char board[21][21];




int dc[4] = {1, -1, 0, 0}; // 동 서 남 북
int dr[4] = {0, 0, -1, 1};
struct coin
{
    int row;
    int col;
};

vector<coin> start;
bool visited[21][21][21][21];
bool isCoinOut(coin cur)
{
    if (0 <= cur.col && cur.col < M && 0 <= cur.row && cur.row < N)
    {
        return false;
    }
    return true;
}

bool isCoinBlock(coin cur)
{
    if (board[cur.row][cur.col] == '#')
    {
        return true; // blocked
    }
    return false;
}

int main(void)
{
    cin >> N >> M;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1c", &board[i][j]);
            if (board[i][j] == 'o')
            {
                coin temp;
                temp.row = i;
                temp.col = j;
                start.push_back(temp); 
            }
        }
        cin.ignore();
    }
    
    queue<vector<coin>> q;
    q.push(start);
    visited[start[0].row][start[0].col][start[1].row][start[1].col] = true;
    int level = 0;
    while(!q.empty())
    {
        int curLevelSize = q.size();
        //cout << "cur Level Size : " << curLevelSize << endl;
        for(int i = 0; i < curLevelSize; i++)
        {
            vector<coin> cur = q.front();
            // cout <<"q front" << endl;
            // cout << level << endl;
            // cout << cur[0].row << cur[0].col << endl;
            // cout << cur[1].row << cur[1].col << endl;
            // search 4direction, 2coins push

            for(int j = 0; j < 4; j++)
            {
                vector<coin> next;
                coin temp1;
                coin temp2;
                temp1 = cur[0];
                temp2 = cur[1];
                temp1.col += dc[j];
                temp1.row += dr[j];
                temp2.col += dc[j];
                temp2.row += dr[j];

                if (isCoinOut(temp1) != isCoinOut(temp2))
                {
                    level++;
                    cout << level << endl;
                    return 0;
                }
                if (isCoinOut(temp1) && isCoinOut(temp2))
                {
                    continue;
                }
                if (isCoinBlock(temp1) && isCoinBlock(temp2))
                {
                    continue;
                }

                if (isCoinBlock(temp1))
                {

                    temp1.col -= dc[j];
                    temp1.row -= dr[j];
                }
                if (isCoinBlock(temp2))
                {

                    temp2.col -= dc[j];
                    temp2.row -= dr[j];
                }

                if (visited[temp1.row][temp1.col][temp2.row][temp2.col])
                {
                    continue;
                }
       
                next.push_back(temp1);
                next.push_back(temp2);
                q.push(next);
                visited[temp1.row][temp1.col][temp2.row][temp2.col] = true;
            }
            q.pop();
        }
        
        level++;
        if (level == 10)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;

}