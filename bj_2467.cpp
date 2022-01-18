#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void) {
    int N;
    int liquid[100000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &(liquid[i]));
    }
    int front = 0;
    int back = N - 1;
    int goal = 2000000000;
    int goalF, goalB;

    while (front < back)
    {
        int temp = liquid[front] + liquid[back];
        if (abs(temp) < goal)
        {
            goal = abs(temp);
            goalF = front;
            goalB = back;
            if (temp == 0)
            {
                break;
            }
            
        }
        
        if (temp > 0)
        {
            back--;
        } else {
            front++;
        }     
    }

    printf("%d %d\n", liquid[goalF], liquid[goalB]);
    return 0;
    
}