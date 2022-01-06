//
//  main.cpp
//  BJ_11650
//
//  Created by LeeMinkyo on 2020/12/27.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct dot {
    int x;
    int y;
};

bool cmp(dot a, dot b) {
    if (a.x < b.x) {
        return true;
    }
    else if (a.x == b.x) {
        return a.y < b.y;
    }
    else {
        return false;
    }
}

int main(void) {
    // insert code here...
    int n;
    cin >> n;
    dot input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i].x;
        cin >> input[i].y;
    }
    
    sort(input, input + n, cmp);
    
    for (int i = 0; i < n; i++) {
        cout << input[i].x << " " << input[i].y << "\n";
    }
    
    return 0;
    
}
