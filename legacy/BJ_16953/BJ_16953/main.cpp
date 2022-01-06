//
//  main.cpp
//  BJ_16953
//
//  Created by LeeMinkyo on 2021/03/02.
//

#include <iostream>
#include <map>
using namespace std;

int ans = -1;

int calc(long cur, long b, int calcTime) {
    if (cur > b) {
        return -1;
    }
    if (cur == b) {
        if (ans > calcTime || ans == -1) {
            ans = calcTime;
        }
        return 0;
    }
    calc(cur * 2, b, calcTime + 1);
    calc(cur * 10 + 1, b, calcTime + 1);
    
    return 0;
}


int main() {
    
    
    long A, B;
    cin >> A >> B;
    
    calc(A, B, 1);
    
    cout << ans << "\n";
    
    return 0;
}
