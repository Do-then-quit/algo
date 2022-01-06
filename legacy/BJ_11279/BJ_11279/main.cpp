//
//  main.cpp
//  BJ_11279
//
//  Created by LeeMinkyo on 2021/01/14.
//

#include <iostream>
#include <algorithm>
#include <limits.h>
//아 뭔가 안이쁜데 ㅡㅡ.
using namespace std;
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int heap[100001];
    int heap_size = 0;
    heap[0] = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (heap_size == 0) {
                cout << heap_size << "\n";
            } else {
                //top cout, pop max.
                cout << heap[1] << "\n";
                heap[1] = heap[heap_size];
                heap_size--;
                int parent = 1;
                int child_L = parent * 2;
                int child_R = child_L + 1;
                
                while (child_L <= heap_size) {  //막 했는데 생각보다 정석대로 한듯? ㅋㅋㅋ
                    if (heap[parent] >= heap[child_L] && heap[parent] >= heap[child_R]) {
                        break;
                    } else {
                        if (heap[child_L] > heap[child_R]) {
                            int temp = heap[child_L];
                            heap[child_L] = heap[parent];
                            heap[parent] = temp;
                            parent = child_L;
                        } else {
                            int temp = heap[child_R];
                            heap[child_R] = heap[parent];
                            heap[parent] = temp;
                            parent = child_R;
                        }
                        child_L = parent * 2;
                        child_R = child_L + 1;
                    }
                }
                
            }
        } else {
            //put x in heap.
            heap_size++;
            heap[heap_size] = x;
            // find position.
            int child = heap_size;
            int parent = heap_size / 2;
            while (true) {
                if (heap[parent] >= heap[child]) {
                    break;
                } else {
                    //swap
                    int temp = heap[parent];
                    heap[parent] = heap[child];
                    heap[child] = temp;
                    child = parent;
                    parent = parent / 2;
                }
            }
            
            
        }
    }
    
    return 0;
}
