//
//  main.cpp
//  BJ_11050
//
//  Created by LeeMinkyo on 2020/12/25.
//

#include <iostream>
using namespace std;
int factorial(int n);
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, k;
    
    cin >> n;
    cin >> k;
   
    int ans = factorial(n)/(factorial(k) * factorial(n - k));
    
    cout << ans << endl;
    return 0;
}

int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
