#include <iostream>

using namespace std;
int main(void)
{
    // N을 K로 나누던가 1을 뺴던가 해서 N을 1로 만들기
    // K로 나누는게 무적권 이득이니 나눌수 있으면 나누자

    int N;
    int K;

    cin >> N >> K;
    int answer = 0;
    while(N != 1)
    {
        int namuji = N % K;
        //cout << N << " " << namuji << endl;
        if (namuji == 0)
        {
            N = N / K;
            answer++;
        } else 
        {
            // 안나눠 떨어지면 나눠떨어지는 수까지 바로 가도 괜찮을 듯
            if (N < K)
            {
                break;
            }
            N -= namuji;
            answer = answer + namuji;
        }
    }
    answer += (N - 1);
    cout << answer;
    return 0;
}