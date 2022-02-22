#include <iostream>
#include <vector>
using namespace std;

int total_memory = 0;
int answer = 10001;
int N, M;
vector<int> m;
vector<int> c;
void dfs(int curIdx, int curMemory, int leftMemory, int cost) {
    if (curMemory >= M)
    {
        // possible case;
        if (cost < answer)
        {
            answer = cost;
        }
        return;
    }
    if (curMemory + leftMemory < M) 
    {   // don't have to search further;
        return;
    }
    if (curIdx == N-1)
    {
        return;
    }
    curIdx++;
    // select
    dfs(curIdx, curMemory + m[curIdx], leftMemory - m[curIdx], cost + c[curIdx]);

    //not select;
    dfs(curIdx, curMemory, leftMemory - m[curIdx], cost);
    
};

int main(void) {
    
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int memory;
        total_memory += memory;
        cin >> memory;
        m.push_back(memory);
    }
    for (int i = 0; i < N; i++)
    {
        int cost;
        
        cin >> cost;
        c.push_back(cost);
    }
    
    dfs(-1, 0, total_memory, 0);

    cout << answer << endl;
    return 0;
    
}