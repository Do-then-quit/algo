#include <iostream>
#include <queue>
#include <map>

using namespace std;


int main(void) {
    int N;
    int ans = -1;
    cin >> N;
    int visited[1000001] = {0,};
    
    
    queue< pair<int, int> > q;
    // cur n, level;
    q.push(pair<int, int>(1, 0));
    //visited.insert(pair<int, int>(1, 0));
    while (q.empty() == false)
    {
        
        pair<int, int> cur = q.front();
        q.pop();
        // cout << "cur : " << cur.first << "secode : " << cur.second << endl;

        if(cur.first == N) {
            ans = cur.second;
            break;
        }

        int next1 = cur.first + 1;
        int next2 = cur.first * 2;
        int next3 = cur.first * 3;

        if(next1 <= N && visited[next1] == 0) {
            // q push, visited insert
            q.push(pair<int, int>(next1, cur.second + 1));
            visited[next1] = 1;
            
        }
        if(next2 <= N && visited[next2] == 0) {
            // q push, visited insert
            q.push(pair<int, int>(next2, cur.second + 1));
            visited[next2] = 2;
            
        }
        if(next3 <= N && visited[next3] == 0) {
            // q push, visited insert
            q.push(pair<int, int>(next3, cur.second + 1));
            visited[next3] = 3;
            
        }
    }

    cout << ans << endl;

    int temp = N;
    while (temp != 1)
    {
        //print temp
        printf("%d ", temp);
        int next = visited[temp];
        if(next == 1) {
            temp = temp - 1;
        } else if (next == 2) {
            temp = temp / 2;
        } else if (next == 3) {
            temp = temp / 3;
        }
    }
    printf("1\n");
    

    return 0;
    

}