#include <iostream>
#include <vector>
#include <utility>
#include <bitset>
using namespace std;
struct node
{
    vector<pair<int, int> > neigh; //first near idx, second value=
};
void dfs(int curidx, int curvalue);

bitset<100001> visited;
node nodes[100001];
int max_value = 0;
int max_index;

int main(void) {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin >> n;

    
    
    for (int i = 1; i <= n; i++)
    {   
        int idx1, idx2;
        int value;

        cin >> idx1;
        while (true)
        {
            int temp;
            cin >> temp;
            if(temp == -1) {
                break;
            }
            idx2 = temp;

            cin >> value;
            nodes[idx1].neigh.push_back(make_pair(idx2, value));
        }      
    }
    
    
    // cout << lastnodes.size() << endl;
    // dfs 
    visited.reset();
    dfs(1, 0);

    max_value = 0;
    visited.reset();
    dfs(max_index, 0);
    // only 2 dfs needed. one for find farthest idx, two for get max_value;
    
    cout << max_value << endl;

    return 0;
    
}

void dfs(int curidx, int curvalue) {
    visited.set(curidx, true);
    for (int i = 0; i < nodes[curidx].neigh.size(); i++)
    {
        if(visited[nodes[curidx].neigh[i].first] == 0) {
            dfs(nodes[curidx].neigh[i].first, curvalue + nodes[curidx].neigh[i].second);
        }
    }

    if(curvalue > max_value) {
        max_value = curvalue;
        max_index = curidx;
    }
}