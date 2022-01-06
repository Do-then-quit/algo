#include <iostream>
using namespace std;

int main(void) {
    int N;
    int two = 0;
    int five = 0;
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        int temp = i;
        while (true)
        {
            if(temp % 2 == 0) {
                two++;
                temp /= 2;
            }
            else {
                break;
            }
        }
        while (true)
        {
            if(temp % 5 == 0) {
                five++;
                temp /= 5;
            }
            else {
                break;
            }
        }
    }

    if (two < five)
    {
        cout << two;
    } else {
        cout << five;
    }
    
    return 0;
}