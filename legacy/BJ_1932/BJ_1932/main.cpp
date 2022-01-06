//
//  main.cpp
//  BJ_1932
//
//  Created by LeeMinkyo on 2021/02/02.
// 이번엔 보이자마자 다이나믹프로그래밍인거 보였다! 자주해보니 익숙해지네 히히

#include <iostream>
using namespace std;

int triangle[500][500];
int memo[500][500];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    memo[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                memo[i][j] = memo[i-1][j] + triangle[i][j];
            } else if (j == i) {
                memo[i][j] = memo[i-1][j-1] + triangle[i][j];
            } else {
                memo[i][j] = max(memo[i-1][j-1], memo[i-1][j]) + triangle[i][j];
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
        if (memo[n-1][j] > ans) {
            ans = memo[n-1][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
