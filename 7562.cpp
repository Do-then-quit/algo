#include <iostream>
#include <queue>
using namespace std;


bool chessPan[300][300];
int T;
int I;

int nightMove[8][2] = {
    {-2, -1},
    {-1, -2},
    {1, 2},
    {2, 1},
    {-2, 1},
    {-1, 2},
    {2, -1},
    {1, -2}
};

struct state
{
    int x;
    int y;
    int curStep;
};



int main(void) {
    cin >> T;

    for (int test = 0; test < T; test++)
    {
        cin >> I;
        for (int j = 0; j < I; j++)
        {
            for (int k = 0; k < I; k++)
            {
                chessPan[j][k] = false;
            }
        }
        
        int startX, startY;
        int endX, endY;
        cin >> startX >> startY;
        cin >> endX >> endY;
        queue< state > q;
        state start;
        start.curStep = 0;
        start.x = startX; start.y = startY;
        chessPan[start.x][start.y] = true;
        q.push(start);

        int ans = 0;
        while (!q.empty()) {
            state cur = q.front();
            q.pop();
            chessPan[cur.x][cur.y] = true;

            if (cur.x == endX && cur.y == endY) {
                // end
                ans = cur.curStep;
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int tempX, tempY;
                tempX = cur.x + nightMove[i][0];
                tempY = cur.y + nightMove[i][1];
                if (tempX < 0 || tempX >= I || tempY < 0 || tempY >= I)
                {
                    continue;
                }
                if (chessPan[tempX][tempY] == true) {
                    continue;
                }
                state next;
                next.x = tempX; next.y = tempY; next.curStep = cur.curStep + 1;
                chessPan[next.x][next.y] = true;
                q.push(next);
            }
        }
        cout << ans << endl;
    }
    

}