#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    vector<long long> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int start = 0;
    int mid = 1;
    int end = N - 1;
    int ans[3];
    long long ansSum = (long long)4000000000;
    long long curSum;
    for (int i = 0; i < N - 2; i++)
    {
        mid = i + 1;
        end = N - 1;
        while (mid < end)
        {
            curSum = v[i] + v[mid] + v[end];
            if(llabs(curSum) < ansSum) {
                ansSum = llabs(curSum);
                ans[0] = i;
                ans[1] = mid;
                ans[2] = end;
                if(curSum == 0) {
                    cout << v[ans[0]] << " " << v[ans[1]] << " " << v[ans[2]];
                    return 0;
                }
            }

            if (curSum > 0)
            {
                end--;
            } else {
                mid++;
            }
        }
        
    }
    
    cout << v[ans[0]] << " " << v[ans[1]] << " " << v[ans[2]];
    return 0;
        
}