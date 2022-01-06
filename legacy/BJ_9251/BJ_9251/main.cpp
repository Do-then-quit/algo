//
//  main.cpp
//  BJ_9251
//
//  Created by LeeMinkyo on 2021/02/08.
//  다이나믹프로그래밍에게 깝치지 말자. 느리더라도 테이블을 그려가면서 해보는게 직관적이고 해결책이 나오네.

#include <iostream>
#include <string>

using namespace std;
int memo[1000][1000];
string a, b;


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a;
    cin >> b;
    
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            int left = 0;
            int up = 0;
            int leftup = 0;
            if (j > 0) {
                left = memo[i][j-1];
            }
            if (i > 0) {
                up = memo[i-1][j];
            }
            if (a[i] == b[j]) {
                if (i > 0 && j > 0) {
                    leftup = memo[i-1][j-1] + 1;
                }
                else {
                    leftup = leftup + 1;
                }
            }
            
            memo[i][j] = max(leftup, max(left, up));
        }
    }
    
    cout << memo[a.size()-1][b.size()-1] << "\n";
    
    
    return 0;
}
