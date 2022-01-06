//
//  main.cpp
//  BJ_1003
//
//  Created by LeeMinkyo on 2021/01/06.
//

#include <iostream>
using namespace std;
struct fibb {
    int zero;
    int one;
};
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    fibb f[41];
    f[0].zero = 1; f[0].one = 0;
    f[1].zero = 0; f[1].one = 1;
    for (int i = 2; i <= 40; i++) {
        f[i].zero = f[i-1].zero + f[i-2].zero;
        f[i].one = f[i-1].one + f[i-2].one;
    }
    
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << f[n].zero << " " << f[n].one << "\n";
    }
    return 0;
}
