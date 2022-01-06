//
//  main.cpp
//  BJ_1920
//
//  Created by LeeMinkyo on 2020/12/28.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    
    int n;
    int m;
    
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cin >> m;
    int find_arr[m];
    
    for (int i = 0; i < m; i++) {
        cin >> find_arr[i];
    }
    
    sort(arr, arr + n);
    for (int i = 0; i < m; i++) {
        if(binary_search(arr, arr + n, find_arr[i])) {  //binary_search 함수를 알게되었다. 미리 정렬하고 쓰면 된다. 
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    
    //no sort : O(mn)
    //sort : O(nlogn + logm)
    return 0;
}
