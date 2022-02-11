// Created on 민교 ipad air 4.

#include <iostream>
#include <vector>

using namespace std;
int memo[1001];
int constructTime[1001];
vector<int> need[1001];

int Construct(int goal);

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        // memo refresh
        for(int j = 0; j < 1001; j++) {
            memo[j] = -1;
            vector<int>().swap(need[j]);
        }
        int N, K;
        cin >> N >> K;
        for(int j = 1; j <= N; j++) {
            cin >> constructTime[j];
        }
        for(int j = 0; j < K; j++) {
            int first, after;
            cin >> first >> after;
            need[after].push_back(first);
        }
        int goal;
        cin >> goal;
        cout << Construct(goal) << endl;
        // input done
    }
    return 0;
}

int Construct(int goal) {
    if(memo[goal] != -1) {
        return memo[goal];
    }
    int prev = 0;
    for(int i = 0; i < need[goal].size(); i++) {
        int cur = Construct(need[goal][i]);
        if ( prev < cur) {
            prev = cur;
        }
    }
    memo[goal] = prev + constructTime[goal];
    return memo[goal];
    
}