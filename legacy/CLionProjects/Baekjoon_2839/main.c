#include <stdio.h>

int main() {
    int n;
    int bag_3 = 0;
    int leftover;
    int bag_5;
    int i;
    int check = 0;
    int sum;

    scanf("%d", &n);

    for(i = 0; ; i++)
    {
        if( n < 3 * i)
        {
            break;
        }
        leftover = (n - 3 * i);
        if(leftover % 5 != 0)
        {
            continue;
        }
        else
        {
            bag_5 = leftover / 5;
            bag_3 = i;
            check = 1;
            sum = bag_3 + bag_5;
            break;
        }

    }
    if(check == 0)
    {
        sum = -1;
    }
    printf("%d\n", sum);
    return 0;
}