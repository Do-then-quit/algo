//
//  main.cpp
//  BJ_11053
//
//  Created by LeeMinkyo on 2021/01/27.
//  음 이것도 dp 냄새가 났는데 이전 인덱스를 모두 뒤져봐야되서 의구심이 들었지만 이것도 memorization
// memo [i] = max(memo[i +1], ....memo[n-1]) + 1 처럼 점화식으로 나타내지네.

#include <iostream>
using namespace::std;

int main() {
    int n;
    cin >> n;
    int A[1000];
    int memo[1000];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    memo[n-1] = 1;
    
    int ans = 1;
    int temp;
    for (int i = n - 1; i >= 0; i--) {
        temp = 0;
        for (int j = i + 1; j < n; j++) {
            if (A[i] < A[j]) {
                if (memo[j] > temp) {
                    temp = memo[j];
                }
            }
        }
        temp++;
        memo[i] = temp;
        if (ans < memo[i]) {
            ans = memo[i];
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
