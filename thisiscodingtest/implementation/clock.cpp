#include <iostream>


//1분당 15개?
//3, 13, 23, 30~39, 43, 53, 
// 1시간당, 0-0 ~ 59-59
// 15 * 60 + 45 * 15 = 1575
// if 3 : 00 : 00 ~ 3 :59 :59, -> 3600;

// or just bruteforce from start to end
// 보통 1초에 2천만번 계산한다. 컴퓨터는

using namespace std;
int main(void)
{
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 0; i <= N; i++)
    {
        if (i == 3 || i == 13 || i == 23)
        {
            answer += 3600;
        } else 
        {
            answer += 1575;
        }
    }

    cout << answer << endl;
    return 0;
}
