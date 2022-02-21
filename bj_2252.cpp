#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int prevWay[32001];
vector<int> way[32001];

int main(void) {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int low, high;
        cin >> low >> high;
        way[low].push_back(high);
        prevWay[high]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (prevWay[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur;
        cur = q.front();
        q.pop();
        printf("%d ", cur);

        // edge erase
        for (int i = 0; i < way[cur].size(); i++)
        {
            int after = way[cur][i];
            prevWay[after]--;
            if(prevWay[after] == 0) {
                q.push(after);
            }
        }
    }

    return 0;
    
    
    
}