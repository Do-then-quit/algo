#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;
int answer = 0;

int main(void) {
    int T;
    //cin >> T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        answer = 0;
        bool searched[100001]; //1 : already search, 0: not yet,
        bool inGroup[100001];
        for (int j = 0; j < 100001; j++)
        {
            searched[j] = false;
            inGroup[j] = false;
        }
        
        int point[100001];
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            //cin >> point[j];
            scanf("%d", &(point[j]));
        }

        for (int j = 1; j <= n; j++)
        {
            if (searched[j])
            {
                continue;
            }
           

            stack<int> way;
            unordered_set<int> cur;
            
            way.push(j);
            cur.insert(j);
            while (!way.empty())
            {
                int top = way.top();
                if(!searched[ point[top] ]) {
                    // in cur or not
                    auto search = cur.find(point[top]);
                    if ( search != cur.end())
                    {
                        //find, calc group, pop way.
                        bool flag = true;
                        while (!way.empty())
                        {
                            int temp = way.top();
                            searched[temp] = true;
                            if (flag)
                            {
                                inGroup[temp] = true;
                                answer++;
                            } else {
                                inGroup[temp] = false;
                            }
                            
                            if (temp == *search && flag == true)
                            {
                                flag = false;
                            }
                            way.pop();                            
                        }
                        break;
                        
                    } else {
                        way.push(point[top]);
                        cur.insert(point[top]);
                    }   
                } else {
                    // all not in group
                    while (!way.empty())
                    {
                        int temp = way.top();
                        way.pop();
                        searched[temp] = true;
                        inGroup[temp] = false;
                    }    
                }
            }
        }
        // print
        //cout << n - answer << endl;
        printf("%d\n", n - answer);
        

        
    }
    return 0;
}
