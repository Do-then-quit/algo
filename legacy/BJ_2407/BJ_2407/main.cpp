//
//  main.cpp
//  BJ_2407
//
//  Created by LeeMinkyo on 2021/01/25.
//

#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

string sumfunc(string a, string b) {
    int short_length;
    int long_length;
    bool isAShort;
    stack<char> s;
    string sum;
    if (a.length() < b.length()) {
        isAShort = true;
        short_length = int(a.length());
        long_length = int(b.length());
    } else {
        isAShort = false;
        short_length = int(b.length());
        long_length = int(a.length());
    }
    int carry = 0;
    for (int i = 0; i < long_length; i++) {
        if (i < short_length) {
            // 문자열을 맞게 더해준다. a + b + carry;
            int temp;
            temp = a[a.length()-1-i] - '0' + b[b.length()-1-i] - '0' + carry;
            if (temp >= 10) {
                temp = temp - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            s.push(temp + '0');
        } else {
            if (isAShort == true) {
                // left b string push
                int temp;
                temp = b[long_length -1 -i] - '0' + carry;
                if (temp >= 10) {
                    temp = temp - 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                s.push(temp + '0');
            } else {
                int temp;
                temp = a[long_length -1 -i] - '0' + carry;
                if (temp >= 10) {
                    temp = temp - 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                s.push(temp + '0');
            }
        }
    }
    if (carry == 1) {
        s.push('1');
    }
    
    //스택에 있는걸 하나씩 팝해서 스트링에 푸시해준다.
    while (s.empty() != true) {
        sum.push_back(s.top());
        s.pop();
    }
    return sum;
}


int main() {
    int n, m;
    cin >> n >> m;
    
    string pascal[n + 1][n + 1];
    pascal[0][0] = "1";
    pascal[1][0] = "1"; pascal[1][1] = "1";
    for (int i = 2; i <= n; i++) {
        pascal[i][0] = "1";
        for (int j = 1; j < i; j++) {
            pascal[i][j] = sumfunc(pascal[i-1][j-1], pascal[i-1][j]);
        }
        pascal[i][i] = "1";
    }
    
    cout << pascal[n][m] << "\n";
    
    return 0;
}
