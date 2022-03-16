#include <iostream>

using namespace std;
int num[2001];
int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d ", &num[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        bool ispalin = true;
        while (s <= e)
        {
            if(num[s] != num[e]) {
                // not palindrum
                ispalin = false;
                break;
            }
            s++;
            e--;
        }
        if (ispalin)
        {
            printf("1\n");
        } else {
            printf("0\n");
        }
        
        
    }
    return 0;
    
}