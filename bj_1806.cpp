#include <iostream>

using namespace std;
int main(void) {
    int num[100000];
    int N, S;
    cin >> N >> S;
    int left, right;
    left = 0; right = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    int cur = num[0];
    if (cur > S)
    {
        cout << 1 << endl;
        return 0;
    }
    
    int len = N + 1;
    while (true)
    {
        //cout << cur << endl;
        if(cur >= S) {
            if (right - left + 1 < len)
            {
                len = right - left + 1;
            }
            cur -= num[left];
            left++;
            if (left > right)
            {
                break;
            }
            
        } else {
            right++;
            if (right >= N)
            {
                break;
            }
            cur += num[right];
        }
        
    }

    if (len == N + 1)
    {
        cout << 0 << endl;
    } else {
        cout << len << endl;
    }
    
    return 0;
    
}