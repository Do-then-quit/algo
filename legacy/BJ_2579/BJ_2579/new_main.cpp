//
//  new_main.cpp
//  BJ_2579
//
//  Created by LeeMinkyo on 2021/01/07.
//

#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int fir[n+1];
    int sec[n+1];
    int stair[n+1];
    fir[0] = 0; sec[0] = 0; stair[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> stair[i];
    }
    if (n == 1) {
        cout << stair[1] << "\n";
        return 0;
    }
    fir[1] = stair[1];
    sec[1] = stair[1];
    for (int i = 2; i <= n; i++) {
        fir[i] = sec[i - 1] + stair[i];
        sec[i] = max(fir[i-2], sec[i-2]) + stair[i];
    }
    cout << max(fir[n], sec[n]) << "\n";
    
    
    
    return 0;
}
