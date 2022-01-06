//
//  main.cpp
//  BJ_9465
//
//  Created by LeeMinkyo on 2021/01/26.
// 다이나믹 프로그래밍(즉 메모리제이션!) 처음에 절대 다이나믹 아닐꺼라고 생각했다. 반으로 쪼갤수 없다고 생각해서
// 그런데 꼭 반이 아니라 한두줄씩 더해지는 방식이라고 생각하니 되더라.
// memo[n] 이 최적일때 memo [n+1]이 최적이 아니라고 가정하면 모순임.
// 암튼 신기하구만. 

#include <iostream>
using namespace std;
int summax = 0;
int sticker[2][100002];
/*
int dfs(int row, int col, int cur, int n) {
    if (col >= n) {
        if (cur > summax) {
            summax = cur;
        }
        return 0;
    }
    cur += sticker[row][col];
    
    if (row == 0) {
        dfs(1, col + 1, cur, n);
        dfs(1, col + 2, cur, n);
    } else if (row == 1){
        dfs(0, col + 1, cur, n);
        dfs(0, col + 2, cur, n);
    }
    return 0;
}
*/


int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int memo[2][n + 2];
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n; k++) {
                cin >> sticker[j][k];
            }
        }
        sticker[0][n] = 0; sticker[0][n+1] = 0;
        sticker[1][n] = 0; sticker[1][n+1] = 0;
        memo[0][n] = 0; memo[0][n+1] = 0;
        memo[1][n] = 0; memo[1][n+1] = 0;
        // calculate. dfs? no dp!
        for (int k = n-1; k >= 0 ; k--) {
            memo[0][k] = sticker[0][k] + max(memo[1][k+1], memo[1][k+2]);
            memo[1][k] = sticker[1][k] + max(memo[0][k+1], memo[0][k+2]);
        }
        
        cout << max(memo[0][0], memo[1][0]) << "\n";
    }
    
    return 0;
}
