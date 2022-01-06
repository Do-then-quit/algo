//
//  main.cpp
//  BJ_7662
//
//  Created by LeeMinkyo on 2021/01/21.
// insert가 너무 느리다. 힙을 써야한다. or priority queue.
// multiset이 있구나... 편하게 풀었다! map으로도 풀수있다는데 어케하는걸까. 

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, K;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> K;
        multiset<int> ms;
        for (int j = 0; j < K; j++) {
            char iord;
            cin >> iord;
            if (iord == 'I') {
                int input;
                cin >> input;
                ms.insert(input);
            } else if (iord == 'D') {
                int temp;
                cin >> temp;
                if (ms.empty() == true) {
                    continue;
                }
                if (temp == -1) {
                    //최소 삭제
                    ms.erase(ms.begin());
                } else {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
            }
        }
        if (ms.empty() == true) {
            cout << "EMPTY\n";
        } else {
            auto iter = ms.end();
            iter--;
            cout << *iter << " " << *(ms.begin()) << "\n";
        }
    }
    
    return 0;
}
