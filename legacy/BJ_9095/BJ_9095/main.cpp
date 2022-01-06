//
//  main.cpp
//  BJ_9095
//
//  Created by LeeMinkyo on 2021/01/09.
//

#include <iostream>
using namespace std;
int ans = 0;

int Calc(int i) {
    if (i < 0) {
        return -1;
    } else if (i == 0) {
        ans++;
        return 0;
    } else {
        Calc(i - 1);
        Calc(i - 2);
        Calc(i - 3);
        return 0;
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int Int;
        cin >> Int;
        ans = 0;
        Calc(Int);
        cout << ans << "\n";
    }
    return 0;
}
