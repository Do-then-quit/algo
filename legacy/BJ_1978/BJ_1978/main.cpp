//
//  main.cpp
//  BJ_1978
//
//  Created by LeeMinkyo on 2020/12/28.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int ans = 0;
    
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            continue;
        }
        int flag = 0;
        for (int j = 2; j < arr[i]; j++) {
            if (arr[i] % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
