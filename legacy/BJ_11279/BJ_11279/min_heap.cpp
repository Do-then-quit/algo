//
//  min_heap.cpp
//  BJ_11279
//
//  Created by LeeMinkyo on 2021/01/19.
//

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int heap[100001];
    int heap_size = 0;
    heap[0] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (heap_size == 0) {
                cout << 0 << "\n";
            }
            else {
                cout << heap[1] << "\n";
                heap[1] = heap[heap_size];
                heap_size--;
                int parent = 1;
                int child_L = parent * 2;
                int child_R = child_L + 1;
                
                while (child_L <= heap_size) {
                    if (heap[parent] <= heap[child_L] && heap[parent] <= heap[child_R]) {
                        break;
                    }
                    else {
                        if (heap[child_L] < heap[child_R]) {
                            swap(heap[child_L], heap[parent]);
                            parent = child_L;
                        } else {
                            swap(heap[child_R], heap[parent]);
                            parent = child_R;
                        }
                        child_L = parent * 2;
                        child_R = child_L + 1;
                    }
                }
            }
        } else {
            heap_size++;
            heap[heap_size] = x;
            
            int child = heap_size;
            int parent = heap_size / 2;
            while (heap[parent] > heap[child]) {
                swap(heap[parent], heap[child]);
                child = parent;
                parent = parent / 2;
            }
        }
    }
    
    return 0;
}
