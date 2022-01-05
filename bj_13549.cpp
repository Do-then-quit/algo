#include <iostream>
#include <queue>
using namespace std;
int main(void) {
    int N;
    int K;
    int arr[100001];
    for (int i = 0; i <= 100000; i++)
    {
        arr[i] = 100000;
    }
    
    queue<int> q;
    cin >> N >> K;
    if ( N > K) {
        cout << N - K;
        return 0;
    }
    arr[K] = 0;

    int temp = K;
    q.push(temp);
    while (temp % 2 == 0) {
        temp = temp / 2;
        q.push(temp);
        arr[temp] = 0;
    }
    // all 0 level in queue
    while(true) {
        int cur = q.front();
        q.pop();
        
        if (cur == N) {
            break;
        }
        int pp = cur + 1;
        int mm = cur - 1;
        int level = arr[cur] + 1;
        if(0 <= pp && pp <= 100000 && arr[pp] > level) {
            arr[pp] = level;
            q.push(pp);
            if (pp == N) {
                break;
            }
            while(pp % 2 == 0 && pp != 0) {
                pp = pp / 2;
                if(arr[pp] > level) {
                    arr[pp] = level;
                    if(pp == N) {
                        cout << arr[N];
                        return 0;
                    }
                    q.push(pp);
                }
            }
        }
        if(0 <= mm && mm <= 100000 && arr[mm] > level) {
            arr[mm] = level;
            if(mm == N) break;
            q.push(mm);
            while(mm % 2 == 0 && mm != 0) {
                mm = mm / 2;
                if(arr[mm] > level) {
                    arr[mm] = level;
                    if(mm == N) {
                        cout << arr[N];
                        return 0;
                    }
                    q.push(mm);
                }
            }
        }
    }
    cout << arr[N];
    return 0;

}