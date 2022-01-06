//
//  main.cpp
//  BJ_1697
//
//  Created by LeeMinkyo on 2021/01/18.
// 이게 그래프 문제였어?
// 큐를 써서 방문할 곳들을 큐에 넣고, 순서대로 또 방문하고 이미 방문한곳은 그만두고.
// https://www.acmicpc.net/source/23621952 여기 참고하자.
// 암튼 나도 메모리제이션 잘했어!

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int cap = max(n, k);
    int ans[cap+1];
    for (int i = n; i >= 0; i--) {
        ans[i] = n - i;
        if (i == k) {
            cout << ans[i] << "\n";
            return 0;
        }
    }
    for (int i = n + 1; i <= k; i++) {
        if (i % 2 == 0) {
            ans[i] = min(ans[i / 2] + 1, ans[i - 1] + 1);
        } else {
            ans[i] = min(min(ans[i / 2] + 2, ans[(i / 2) + 1] + 2), ans[i - 1] + 1);
        }
    }
    cout << ans[k] << "\n";
    return 0;
}
