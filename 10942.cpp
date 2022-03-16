#include <iostream>

using namespace std;
int num[2001];
int palin[2001];
int palinEven[2001];
int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d ", &num[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int s, e;
        s = i - 1; e = i + 1;
        int howFar = 0;
        while (s >= 1 && e <= n)
        {
            if (num[s] != num[e])
            {
                break;
            }
            howFar++;
            s--; e++;
        }
        palin[i] = howFar;    

        howFar = 0;
        s = i; e = i + 1;  
        while (s >= 1 && e <= n)
        {
            if (num[s] != num[e])
            {
                break;
            }
            howFar++; s--; e++;
        }
        palinEven[i] = howFar;     
    }
    

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        bool isOdd = true;  // odd numbers comp
        if ((s + e) % 2 == 0)
        {
            isOdd = true;
        } else {
            isOdd = false;
        }

        if (isOdd)
        {
            int mid = (s + e) / 2;
            if((e - mid) <= palin[mid]) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else {
            int mid = (s + e) / 2;
            if((e - mid) <= palinEven[mid]) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
        
        
        
    }
    return 0;
    
}