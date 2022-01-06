//
//  main.cpp
//  BJ_1149
//
//  Created by LeeMinkyo on 2021/01/30.
// 1 2 100
// 1 2 2
// 100 1 100
// 다이나믹 프로그래밍 재밌당. 메모리제이션하는 방법을 빨리 떠올리는것도 중요하네.

#include <iostream>
using namespace std;
struct House {
    int R;
    int G;
    int B;
    int memoR;
    int memoG;
    int memoB;
};



int main() {
    int N;
    cin >> N;
    House h[N];
    for (int i = 0; i < N; i++) {
        cin >> h[i].R >> h[i].G >> h[i].B;
    }
    h[0].memoR = h[0].R;
    h[0].memoG = h[0].G;
    h[0].memoB = h[0].B;
    
    for (int i = 1; i < N; i++) {
        h[i].memoR = min(h[i-1].memoG, h[i-1].memoB) + h[i].R;
        h[i].memoG = min(h[i-1].memoR, h[i-1].memoB) + h[i].G;
        h[i].memoB = min(h[i-1].memoR, h[i-1].memoG) + h[i].B;
    }
    cout << min(min(h[N-1].memoR, h[N-1].memoG), h[N-1].memoB) << "\n";
    return 0;
}
