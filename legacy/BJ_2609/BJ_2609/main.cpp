//
//  main.cpp
//  BJ_2609
//
//  Created by LeeMinkyo on 2020/12/25.
//

#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    int r = a % b;
    if (r == 0) {
        return b;
    }
    else {
        return gcd(b, r);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b;
    cin >> a;
    cin >> b;
    int ans_gcd = gcd(a, b);
    printf("%d\n", ans_gcd);
    printf("%d\n", a * b / ans_gcd);
    
    
    return 0;
}
