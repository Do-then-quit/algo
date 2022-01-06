//
//  main.cpp
//  BJ_15650
//
//  Created by LeeMinkyo on 2021/01/23.
// 이야 재귀 오랜만에 하니까 쉽지않네. 조합을 재귀로 짜본적도 없고 이렇게 출력하는것도 처음인데
// 신기하다. 조합에대한 점화식? 재귀공식을 알면 구현이 생각보다 할만하다.
// 그러니 이런거 점화식을 알아두거나 모르면 아이패드 메모로 써가면서 찾자.
// 그냥 모니터만 보고 생각하는 것보다 작은 예를 써가면서 하는게 이해도 잘되고 의미도 있는듯.

#include <iostream>

using namespace std;

int ans[8];

void combination(int n, int m, int now, int depth) {
    
    if (m > 0 && n >= m) {
        ans[depth] = now;
        combination(n - 1, m - 1, now + 1, depth + 1);
        combination(n - 1, m, now + 1, depth);
    }
    if (m == 0) {
        // print
        for (int i = 0; i < depth; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (n < m) {
        // not choosing, return.
        return;
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    //now 1 부터 시작. depth 0부터.
    combination(n, m, 1, 0);
    return 0;
}
