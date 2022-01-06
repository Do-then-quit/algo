//
//  main.cpp
//  BJ_2630
//
//  Created by LeeMinkyo on 2021/01/08.
//

#include <iostream>
using namespace std;
int blue = 0;   //1
int white = 0;  //0
bool input[128][128];
int cut(int n, int i, int j) {
    if (n == 1) {
        input[i][j] ? blue++ : white++;
        return 0;
    }
    
    int check_w = 0;
    for (int row = i; row < n + i; row++) {
        for (int col = j; col < n + j; col++) {
            if (input[row][col] == 1) {
                check_w = 1;
                break;
            }
        }
        if (check_w == 1) {
            break;
        }
    }
    if (check_w == 0) {
        white++; return 0;
    }
    
    int check_b = 0;
    for (int row = i; row < n + i; row++) {
        for (int col = j; col < n + j; col++) {
            if (input[row][col] == 0) {
                check_b = 1;
                break;
            }
        }
        if (check_b == 1) {
            break;
        }
    }
    if (check_b == 0) {
        blue++; return 0;
    }
    
    //cut. 4ways.
    int next_n = n / 2;
    cut(next_n, i, j);
    cut(next_n, i + next_n, j);
    cut(next_n, i, j + next_n);
    cut(next_n, i + next_n, j + next_n);

    return 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    cut(n, 0, 0);
    
    cout << white << "\n";
    cout << blue << "\n";
    
    return 0;
}
