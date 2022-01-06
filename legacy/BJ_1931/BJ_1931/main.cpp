//
//  main.cpp
//  BJ_1931
//
//  Created by LeeMinkyo on 2021/01/13.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct Conference {
    int start;
    int end;
};

bool cmp(Conference a, Conference b) {
    if (a.end != b.end) {
        return a.end < b.end;
    } else {
        return a.start < b.start;
    }
}

int main() {
    ios_base::sync_with_stdio(0);   //cin 을 엄청 하는경우에는 이거 하면 엄청 빨라진다.
    cin.tie(0);
    int n;
    cin >> n;
    Conference table[n];
    for (int i = 0; i < n; i++) {
        cin >> table[i].start >> table[i].end;
    }
    sort(table, table + n, cmp);
    
    int ans = 0;
    int before_end = 0;
    for (int i = 0; i < n; i++) {   //메모 참고하면 됨. 끝나는 시간을 오름차순으로 정렬하면 순서대로 한번만 탐색해서 넣을수 있다. 그리디맞지 ㅇㅇ
        if (table[i].start >= before_end) {
            ans++;
            before_end = table[i].end;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
