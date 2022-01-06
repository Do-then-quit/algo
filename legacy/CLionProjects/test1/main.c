#include <stdio.h>

int main(void)
{
    int t;
    int i;
    int a, b;
    scanf("%d", &t);
    for(i = 1 ; i <= t; i++)
    {
        scanf("%d %d", &a, &b);
        printf("5%d\n",a + b);
    }
    return 0;
}