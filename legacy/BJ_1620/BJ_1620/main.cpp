//
//  main.cpp
//  BJ_1620
//
//  Created by LeeMinkyo on 2021/01/05.
//
//unordered_map 을 사용하면 더 빠르고 좋다? 키가 문자열이고 밸류가 정수인 그런 자료구조로 아래처럼 문자열로 정수를 찾을때에는 map(트리구조, 키가 정렬되어 저장)이나 unordered_map(해시함수사용, 키가 정렬되어있지 않음)을 사용하자. 일종의 해시? #include <map> 이런식으로 포함하여 사용.
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
struct Dogam {
    int idx;
    string name;
};
bool comp_str(Dogam a, Dogam b) {
    return a.name < b.name;
}
bool comp_idx(Dogam a, Dogam b) {
    return a.idx < b.idx;
}
int binarySearchString(Dogam d[], string x, int n) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int res;
        if (x == d[mid].name) {
            res = 0;
            return d[mid].idx;
        }
        if (x > d[mid].name) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    cin >> m;
    Dogam dogam[n];
    string dogam_str[n];
    for (int i = 0; i < n; i++) {
        cin >> dogam[i].name;
        dogam_str[i] = dogam[i].name;
        dogam[i].idx = i + 1;
    }
    sort(dogam, dogam + n, comp_str);
    
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (str[0] >= 'A' && str[0] <= 'Z') {
            
            cout << binarySearchString(dogam, str, n) << "\n";
        } else {
            int x;
            stringstream int_s(str);    //stringstream으로 인풋받는걸 편하게 할수있다. sstream을 인클루드하자.
            int_s >> x;
            cout << dogam_str[x-1] << "\n";
        }
       
    }
    return 0;
}
