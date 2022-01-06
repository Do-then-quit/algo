//
//  main.cpp
//  BJ_9663
//
//  Created by LeeMinkyo on 2021/02/09.
//  이런게 백트래킹이다~. 더 들어갈필요없으면 더 탐색하지않는~. 

#include <iostream>
using namespace std;
int N;
int ans = 0;
int col[16];

int calc(int prevRow) {
    if (prevRow == N) {
        ans++;
        return 0;
    }
    int curi = prevRow + 1;
    for (int curj = 1; curj <= N; curj++) {
        bool okay = true;
        for (int i = 1; i < curi; i++) {
            if (curj == col[i]) {
                okay = false;
                break;
            }
            if (abs(i - curi) == abs(col[i] - curj)) {
                okay = false;
                break;
            }
        }
        //past check done.
        if (okay) {
            col[curi] = curj;
            calc(curi);
        }
    }
    return 0;
}

int main() {
    
    cin >> N;
    calc(0);
    
    cout << ans << "\n";
    
    return 0;
}
