//
//  main.cpp
//  BJ_2579
//
//  Created by LeeMinkyo on 2021/01/07.
//

#include <iostream>
using namespace std;
int Max = 0;
int stairs[301];
int stair_num;
void calc(int idx, int now, int combo) {
    now = now + stairs[idx];
    if (idx == stair_num) {
        if (now > Max) {
            Max = now;
        }
    } else {
        if (combo < 2) {
            calc(idx + 1, now, combo + 1);
        }
        if (idx + 2 <= stair_num) {
            calc(idx + 2, now, 1);
        }
    }
}

int main() {
    cin >> stair_num;
    stairs[0] = 0;
    for (int i = 1; i <= stair_num; i++) {
        cin >> stairs[i];
    }
    calc(0, 0, 0);
    cout << Max << "\n";
    return 0;
}
