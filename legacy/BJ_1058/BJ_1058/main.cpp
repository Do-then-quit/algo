//
//  main.cpp
//  BJ_1058
//
//  Created by LeeMinkyo on 2021/03/03.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
bool f[50][50];
vector<int> flist[50];
vector<int> f2list[50];
int ans = 0;

int main() {
    char c;
    
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            if (c == 'N') {
                f[i][j] = false;
            }
            if (c == 'Y') {
                f[i][j] = true;
                flist[i].push_back(j);
            }
        }
        getchar();
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            if (f[i][j] == false) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < N; k++) {
                    if (f[j][k] == true) {
                        vector<int>::iterator it;
                        
                        it = find(flist[i].begin(), flist[i].end(), k);
                        if (it != flist[i].end()) {
                            f2list[i].push_back(j);
                            break;
                        }
                    }
                }
            }
        }
        int temp = int(flist[i].size() + f2list[i].size());
        if (ans < temp) {
            ans = temp;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
