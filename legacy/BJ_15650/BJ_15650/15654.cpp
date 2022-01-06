//
//  15654.cpp
//  BJ_15650
//
//  Created by LeeMinkyo on 2021/01/24.
// 일종의 dfs 이걸 왜 어렵게 풀었지. 조합을 너무 써먹으려다가 해맸다.
// 그냥 순서대로 하고 이미 탐색했는지를 bool 배열에 저장하면서 돌면 편했을것을...
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ans[8];

void combination(int n, int m, int depth, vector<int> data) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    vector<int>::iterator it;
    int i = 0;
    for (it = data.begin(); it != data.end(); it++, i++) {
        ans[depth] = *it;
        vector<int> temp = data;
        temp.erase(temp.begin() + i);
        combination(n, m, depth + 1, temp);
    }
};


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    //now 1 부터 시작. depth 0부터.
    combination(n, m, 0, v);
    return 0;
}
