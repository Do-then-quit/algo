//
//  BJ_1764_new.cpp
//  BJ_1764
//
//  Created by LeeMinkyo on 2021/01/06.
//

#include <iostream>
#include <set>
using namespace std;
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<string> s;
    set<string>::iterator it;
    set<string> ans;
    
    int N, M;
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (s.find(str) != s.end()) {
            ans.insert(str);
        }
    }
    cout << ans.size() << "\n";
    for (it = ans.begin(); it != ans.end(); it++) {
        cout << *it << "\n";
    }
    return 0;
}
