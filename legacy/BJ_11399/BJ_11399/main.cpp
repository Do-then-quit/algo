//
//  main.cpp
//  BJ_11399
//
//  Created by LeeMinkyo on 2021/01/10.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (n - i) * p[i];
    }
    cout << ans << "\n";
    return 0;
}
