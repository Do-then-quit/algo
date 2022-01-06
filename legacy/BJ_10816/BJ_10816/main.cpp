//
//  main.cpp
//  BJ_10816
//
//  Created by LeeMinkyo on 2020/12/30.
//

#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &(arr[i]));
    }
    sort(arr, arr + n);
    
    int m;
    scanf("%d", &m);
    int find_arr[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &(find_arr[i]));
    }
    
    int ans[m];
    for (int i = 0; i < m; i++) {
        ans[i] = 0;
        int low = 0;
        int high = n - 1;
    
        while (true) {
            if (low > high) {
                break;
            }
            int mid = (low + high) / 2;
            if (arr[mid] < find_arr[i]) {
                low = mid + 1;
            }
            else if (arr[mid] == find_arr[i]) {
                int left_low = 0;
                int left_high = mid;
                while (true) {  //left_low
                    if( left_low > left_high) {
                        break;
                    }
                    int left_mid = (left_low + left_high) / 2;
                    
                    if (arr[left_mid] != find_arr[i]) {
                        left_low = left_mid + 1;
                    } else {
                        left_high = left_mid - 1;
                    }
                }
                int right_low = mid;
                int right_high = n - 1;
                while (true) {  //right_high
                    if( right_low > right_high) {
                        break;
                    }
                    int right_mid = (right_low + right_high) / 2;
                    
                    if (arr[right_mid] != find_arr[i]) {
                        right_high = right_mid - 1;
                    } else {
                        right_low = right_mid + 1;
                    }
                }
                ans[i] = right_high - left_low + 1;
                // 여기도 바이너리 서치? left 가 우리가 찾는 인덱스.
                break;
            }
            else {
                high = mid - 1;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}
