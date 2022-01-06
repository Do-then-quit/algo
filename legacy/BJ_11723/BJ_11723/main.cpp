//
//  main.cpp
//  BJ_11723
//
//  Created by LeeMinkyo on 2021/01/04.
//

#include <iostream>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool S[21] = {0,};
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (str == "add") {
            int x;
            cin >> x;
            S[x] = 1;
        } else if (str == "remove") {
            int x;
            cin >> x;
            S[x] = 0;
        } else if (str == "check") {
            int x;
            cin >> x;
            if (S[x] == 0) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        } else if (str == "toggle") {
            int x;
            cin >> x;
            if (S[x] == 0) {
                S[x] = 1;
            } else {
                S[x] = 0;
            }
        } else if (str == "all") {
            for (int j = 1; j <= 20; j++) {
                S[j] = true;
            }
        } else if (str == "empty") {
            for (int j = 1; j <= 20; j++) {
                S[j] = false;
            }
        }
    }
    return 0;
}
