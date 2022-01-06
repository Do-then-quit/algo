//
//  main.cpp
//  BJ_1629
//
//  Created by LeeMinkyo on 2021/01/31.
// 분할정복? 너무 오랜만이네... 어떻게 쪼개지.
// 문제를 잘읽자... 제곱수를 나누는거였다.
// 멍하니 모니터만 보고 생각하지말고 쓰면서 생각하자. 확실히 고민의 질이 다르다.
// 비트연산으로도 할수있나보다. 비트연산도 잘 알아두자. 

#include <iostream>
#include <limits>
using namespace std;

long long calc(long long a, long long b, long long c) {
    if (b == 1) {
        return a;
    }
    else {
        long long temp;
        if (b % 2 == 0) {
            temp = calc(a, b / 2, c);
            return (temp * temp) % c;
        }
        else {
            return (calc(a, b-1, c) * a) % c;
        }
    }
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    a %= c;
    cout << calc(a, b, c) << "\n";
    return 0;
}
