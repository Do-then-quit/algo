//
//  main.cpp
//  BJ_18870
//
//  Created by LeeMinkyo on 2021/01/17.
// 정렬 두번해서 쭈루룩 출력했다~. 

#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
    int original_x;
    int idx;
    int compressed_x;
};

bool cmp_org(Data a, Data b) {
    return a.original_x < b.original_x;
}

bool cmp_idx(Data a, Data b) {
    return a.idx < b.idx;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    Data X[n];
    for (int i = 0; i < n; i++) {
        cin >> X[i].original_x;
        X[i].idx = i;
    }
    sort(X, X + n, cmp_org);
    
    int new_x = 0;
    X[0].compressed_x = new_x;
    for (int i = 1; i < n; i++) {
        if (X[i].original_x > X[i-1].original_x) {
            X[i].compressed_x = new_x + 1;
            new_x++;
        } else {
            X[i].compressed_x = new_x;
        }
    }
    
    sort(X, X + n, cmp_idx);
    for (int i = 0; i < n; i++) {
        cout << X[i].compressed_x << " ";
    }
    cout << "\n";
    
    return 0;
}
