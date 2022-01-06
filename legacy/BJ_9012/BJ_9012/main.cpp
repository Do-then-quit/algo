//
//  main.cpp
//  BJ_9012
//
//  Created by LeeMinkyo on 2020/12/29.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        int check = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(') {
                check++;
            }
            else {
                check--;
                if (check < 0) {
                    break;
                }
            }
        }
        
        if (check == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
