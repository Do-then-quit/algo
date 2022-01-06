//
//  main.cpp
//  BJ_2164
//
//  Created by LeeMinkyo on 2020/12/29.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    deque<int> dq;
    
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    
    while (dq.size() > 1) {
        dq.pop_front();
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }
    
    cout << dq.front() << "\n";
    return 0;
}
