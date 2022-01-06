//
//  main.cpp
//  BJ_1764
//
//  Created by LeeMinkyo on 2021/01/06.
//

#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(void) {
    map<string, int> m;
    map<string, int>::iterator it;
    
    int N, M;
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        m[str] = 1;
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (m[str] == 1) {
            m[str] = 2;
            ans++;
        } else {
            m[str] = 1;
        }
    }
    cout << ans << "\n";
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second == 2) {
            cout << it->first << "\n";
        }
    }
    return 0;
}
