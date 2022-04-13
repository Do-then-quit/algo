#include <iostream>
using namespace std;
bool skWin[1010];

int main(void) {
    int N;
    cin >> N;
    skWin[1] = false;
    skWin[2] = true;
    skWin[3] = false;
    skWin[4] = true;

    for (int i = 5; i <= N; i++)
    {
        if(skWin[i-1] && skWin[i-3] && skWin[i-4]) {
            skWin[i] = false;
        } else {
            skWin[i] = true;
        }
    }
    
    if (skWin[N])
    {
        cout << "SK" << endl;
    } else {
        cout << "CY" << endl;
    }
    
    return 0;
}