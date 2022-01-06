//
//  main.cpp
//  BJ_1012
//
//  Created by LeeMinkyo on 2021/01/12.
//

#include <iostream>
using namespace std;
bool farm[50][50];
int Bug(int x_cur, int y_cur, int M, int N) {   //이게 dfs 일지도? 꺄르르, bfs로 구하는 연습도 하면 좋을까? 귀찮네... bfs는 또 기회가 있겠지.
    farm[x_cur][y_cur] = false;
    if (x_cur > 0 && farm[x_cur - 1][y_cur] == true) {
        Bug(x_cur - 1, y_cur, M, N);
    }
    if (x_cur < M - 1 && farm[x_cur + 1][y_cur] == true) {
        Bug(x_cur + 1, y_cur, M, N);
    }
    if (y_cur > 0 && farm[x_cur][y_cur - 1] == true) {
        Bug(x_cur, y_cur - 1, M, N);
    }
    if (y_cur < N - 1 && farm[x_cur][y_cur + 1] == true) {
        Bug(x_cur, y_cur + 1, M, N);
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n, k;
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            farm[x][y] = true;
        }
        
        int ans = 0;
        
        for (int garo = 0; garo < m; garo++) {
            for (int sero = 0; sero < n; sero++) {
                if (farm[garo][sero] == true) {
                    ans++;
                    Bug(garo, sero, m, n);
                }
            }
        }
        
        cout << ans << "\n";
        
    }
    return 0;
}
