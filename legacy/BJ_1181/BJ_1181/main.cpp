//
//  main.cpp
//  BJ_1181
//
//  Created by LeeMinkyo on 2020/12/25.
//

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct input_data {
    char input[51];
    int len;
};

bool compare(input_data a, input_data b) {
    if(a.len == b.len) {
        return strcmp(a.input, b.input) < 0;
    }
    else {
        return a.len < b.len;
    }
}
input_data d[20000];
int n;
int main(int argc, const char * argv[]) {
    // insert code here...
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> d[i].input;
        d[i].len = strlen(d[i].input);
        
    }
    sort(d, d+n, compare);  //sort함수의 작동법에 대해서 공부하게 되었다! 3번째항을 compare함수를 잘짜면 유용.
    cout << d[0].input << '\n';
    for (int i = 1; i < n; i++) {
        if (strcmp(d[i].input, d[i-1].input) == 0) {
            continue;
        }
        cout << d[i].input << '\n'; //endl 으로는 840ms였던것이 \n으로는 16ms!!! 말이돼?
        // printf 가 cout보다도 빠르다.
    }
    
    return 0;
}
