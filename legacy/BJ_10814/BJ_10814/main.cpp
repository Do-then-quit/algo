//
//  main.cpp
//  BJ_10814
//
//  Created by LeeMinkyo on 2020/12/26.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct person {
    int age;
    char name[101];
};

bool cmp(person a, person b) {
    if (a.age < b.age) {
        return true;
    }
    else {
        return false;
    }
    
}
int main(void) {
    // insert code here...
    int n;
    cin >> n;
    person input[n];
    
    for (int i = 0; i < n; i++) {
        cin >> input[i].age;
        cin >> input[i].name;
    }
    stable_sort(input, input + n, cmp); //알고리즘 헤더에 좋은게 많구만, cmp함수와 같이 쓰면 구조체 정렬에 좋다.
    for (int i = 0; i < n; i++) {
        cout << input[i].age << " " << input[i].name << "\n";
    }
    return 0;
}
