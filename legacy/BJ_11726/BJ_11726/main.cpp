//
//  main.cpp
//  BJ_11726
//
//  Created by LeeMinkyo on 2021/01/11.
//

#include <iostream>

//Fibonacci, or dp.
using namespace std;
int main() {
    int n;
    cin >> n;
    int Fib[n+1];
    Fib[0] = 1;
    Fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        Fib[i] = (Fib[i-1] + Fib[i-2]) % 10007; //값이 엄청 크구나... 괜히 나머지를 출력하라는게 아닌가 봅니다. 덧셈을 할때도 그 나머지가 유지가 되나? 되겠지 ㅇㅇ;
    }
    cout << Fib[n] << "\n";
    
    return 0;
}
