#include <iostream>

using namespace std;

int dp[10001][101];
int memory[101];
int cost[101];
int main(void) {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> memory[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }

    for (int c = 0; c < 10001; c++)
    {
        for (int i = 0; i < N; i++)
        {
            int up = 0;
            int upleft = 0;
            if(i > 0) {
                up = dp[c][i-1];
                if (c - cost[i] >= 0)
                {
                    upleft = dp[c-cost[i]][i-1];
                }
            }
            
            if (c - cost[i] >= 0)
            {
                dp[c][i] = max(upleft + memory[i], up);
            } else {
                dp[c][i] = up;
            }
    
            if (dp[c][i] >= M)
            {
                cout << c << endl;
                return 0;
            }   
        }   
    }   
}