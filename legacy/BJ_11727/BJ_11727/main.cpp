//
//  main.cpp
//  BJ_11727
//
//  Created by LeeMinkyo on 2021/01/11.
//

#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int Tile[n+1];
    Tile[0] = 1;
    Tile[1] = 1;
    //Tile[n] = 2*Tile[n-2] + Tile[n-1]
    for (int i = 2; i <= n; i++) {
        Tile[i] = (2*Tile[i-2] + Tile[i-1]) % 10007;
    }
    cout << Tile[n] << "\n";
    
    return 0;
}
