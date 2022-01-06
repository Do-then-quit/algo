#include <iostream>
#include <climits>

using namespace std;

int main(void) {
    int n, m;
    int D[101][101];
    //int W[101][101];
    cin >> n;
    cin >> m;
    for (int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++) {
            //W[i][j] = INT_MAX;
            D[i][j] = 10000000;
            if(i == j) {
                D[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b, value;
        scanf("%d %d %d", &a, &b, &value);
        if (D[a][b] < value)
        {
            continue;
        }
        
        D[a][b] = value;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
            
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (D[i][j] == 10000000)
            {
                printf("0 ");
            } else {
                printf("%d ", D[i][j]);
            }
            
            
        }
        printf("\n");
    }
    
    return 0;
    
}