//
//  main.cpp
//  BJ_11660
//
//  Created by LeeMinkyo on 2021/02/04.
//  단순한데 많이 한다? 다이나믹프로그래밍으로 메모해서 시간을 줄이자.
//  간단하게 메모할 방법을 찾자. 다들 입력받자마자 메모할수있는 계산식을 세웠더라. 왼쪽위 영역들을 더하는 방식으로.
//  아무튼 신기방기 dp세상.

#include <iostream>
#include <vector>
using namespace std;

struct table {
    int data;
    int sumTilEnd;
    int sumTilEnd_2;
};



int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    
    table t[n+2][n+2];
    t[n+1][n+1].sumTilEnd_2 = 0;
    
    for (int i = 1; i <= n; i++) {
        t[i][n+1].sumTilEnd = 0;
        t[i][n+1].sumTilEnd_2 = 0;
        for (int j = 1; j <= n; j++) {
            cin >> t[i][j].data;
            t[n+1][j].sumTilEnd_2 = 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            t[i][j].sumTilEnd = t[i][j+1].sumTilEnd + t[i][j].data;
        }
    }
    
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            t[i][j].sumTilEnd_2 = t[i+1][j].sumTilEnd_2 + t[i][j].sumTilEnd;
        }
    }
    
    
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        int sum = 0;

        cin >> x1 >> y1 >> x2 >> y2;
        
        sum = t[x1][y1].sumTilEnd_2 - t[x1][y2+1].sumTilEnd_2 - t[x2+1][y1].sumTilEnd_2 + t[x2+1][y2+1].sumTilEnd_2;
        
        cout << sum << "\n";
    }
    return 0;
}
