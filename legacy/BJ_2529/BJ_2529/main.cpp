//
//  main.cpp
//  BJ_2529
//
//  Created by LeeMinkyo on 2021/03/04.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long ansMax = 0;
long ansMin = 10000000000;

int k;

long table[10];
char foo[9];

bool promising (int col) {
    int pastCol = 0;
    bool check = true;
    
    if (col == -1) {
        return true;
    }
    
    if (col != 0) {
        if (foo[col-1] == '>') {
            if (table[col-1] <= table[col]) {
                return false;
            }
        } else if (foo[col-1] == '<') {
            if (table[col-1] >= table[col]) {
                return false;
            }
        }
    }
    
    while (pastCol < col && check) {
        if (table[pastCol] == table[col]) {
            check = false;
        }
        pastCol++;
    }
    
    return check;
}

void numbers (int col) {
    int numb;
    
    if (promising(col)) {
        if (col == k) {
            // 올바른 숫자 찾음,
            long temp = 0;
            for (int i = 0; i < k + 1; i++) {
                temp = temp * 10;
                temp = temp + table[i];
            }
            if (temp > ansMax) {
                ansMax = temp;
            }
            if (temp < ansMin) {
                ansMin = temp;
            }
        }
        else {
            for (numb = 0; numb <= 9; numb++) {
                table[col+1] = numb;
                numbers(col+1);
            }
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> foo[i];
    }
    
    numbers(-1);
    
    cout << ansMax << "\n";
    
    int minComp = 1;
    for (int i = 0; i < k; i++) {
        minComp = minComp * 10;
    }
    if (ansMin < minComp) {
        cout << 0;
    }
    cout << ansMin << "\n";
    
    return 0;
}
