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

bitset<10001> visited;
node nodes[10001];
int max_value = 0;

int main(void) {
    int n;
    cin >> n;

    
    vector<int> lastnodes;
    visited.reset();
    for (int i = 1; i < n; i++)
    {   
        int idx1, idx2;
        int value;
        cin >> idx1 >> idx2 >> value;
        nodes[idx1].neigh.push_back(make_pair(idx2, value));
        nodes[idx2].neigh.push_back(make_pair(idx1, value));
        visited.set(idx1, true);
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            lastnodes.push_back(i);
        }
    }
    
    // cout << lastnodes.size() << endl;
    // dfs 
    for(int i = 0; i < lastnodes.size(); i++) {
        visited.reset();
        dfs(lastnodes[i], 0);
    }
    // see bj_1967new.cpp for better result.

    cout << max_value << endl;
    
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
    }
}