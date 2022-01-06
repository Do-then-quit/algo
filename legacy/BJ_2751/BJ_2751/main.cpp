//
//  main.cpp
//  BJ_2751
//
//  Created by LeeMinkyo on 2020/12/25.
//
/*
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    scanf("%d", &n);
    int arr[1000000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
} */
#include <iostream>
using namespace std;
bool arr[2000001]; //전역변수 그니까 바깥에서 제일 먼저 선언하면 다 0으로 되어있나?
int main(void) {
    // insert code here...
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;
    //bool arr[2000001];  //메인에서 선언하면 쓰레기값이 들어있는경우가 있나?
    cin >> n;
    
   // bool arr[2000001] = {0,};
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[tmp + 1000000] = 1;
    }
    for (int i = 0; i < 2000001; i++) {
        if(arr[i]) {
            printf("%d\n", i-1000000);
        }
    }
    return 0;
}
