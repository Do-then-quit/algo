#include <iostream>
#include <cmath>

using namespace std;

struct dot
{
    double x;
    double y;
};

int main(void) {
    int N;
    cin >> N;
    dot dots[10001];
    for (int i = 0; i < N; i++)
    {
        cin >> dots[i].x >> dots[i].y;
    }

    // calculate 
    double ans = 0.0;
    for (int i = 0; i < N - 1; i++)
    {
        ans = ans + (dots[i].x * dots[i+1].y);
    }
    ans = ans + (dots[N-1].x * dots[0].y);

    for (int i = 0; i < N - 1; i++)
    {
        ans = ans - (dots[i+1].x * dots[i].y);
    }
    ans = ans - (dots[0].x * dots[N-1].y);

    ans = abs(ans) / 2.0;
    printf("%.1f", ans);
    return 0;
    
}