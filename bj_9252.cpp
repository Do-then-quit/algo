#include <iostream>
#include <string>
#include <stack>

using namespace std;
int memo[1000][1000];
int main(void) {
    string a;
    string b;
    cin >> a;
    cin >> b;

    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            //printf("test %d %d\n", i, j);
            int left, up, leftup;
            left = 0; up = 0; leftup = 0;
            if (i > 0)
            {
                up = memo[i-1][j];
            }
            if (j > 0)
            {
                left = memo[i][j-1];
            }
            if (i > 0 && j > 0)
            {
                leftup = memo[i-1][j-1];
            }
            
            if (a[i] == b[j])
            {
                leftup++;
            }

            memo[i][j] = max(leftup, max(left, up));
        }
    }

    
    int i = a.length() - 1;
    int j = b.length() - 1;
    cout << memo[i][j] << endl;

    // find way
    stack<char> s;
    
    while (i >= 0 && j >= 0)
    {
        //printf("tested %d %d\n", i, j);
        int left, up, leftup;
        left = 0; up = 0; leftup = 0;
        if (i > 0)
        {
            up = memo[i-1][j];
        }
        if (j > 0)
        {
            left = memo[i][j-1];
        }
        if (i > 0 && j > 0)
        {
            leftup = memo[i-1][j-1];
        }

        if (a[i] == b[j])
        {
            //printf("%c", a[i]);
            s.push(a[i]);
            i--; 
            j--;
        } else {
            if (left > up)
            {
                j--;
            } else {
                i--;
            }
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    //cout << endl;
    return 0;
    
}