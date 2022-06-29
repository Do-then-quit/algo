#include <iostream>
#include <array>
#include <math.h>
using namespace std;

array<array<int, 10>, 10> table;

bool IsSquare(int num) {
    int temp = (int)(sqrt((double)num) + 0.5);
    return temp * temp == num;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &table[i][j]);
        }
    }

    int ans = -1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // self check 
            if (table[i][j] > ans) {
                if(IsSquare(table[i][j])) {
                    ans = table[i][j];
                }
            }
            // setting 

            for(int di = -(N-1); di < N; di++) {
                for(int dj = -(M-1); dj < M; dj++) {
                    // 최대 9자리수 완성 가능
                    int curNum = table[i][j];

                    if (di == 0 && dj == 0) {
                        continue;
                    }

                    // setting

                    // for 1~9 , 
                    for (int it = 1; it < 10; it++)
                    {
                        // boundary check
                        int nextI, nextJ;
                        nextI = i + it * di;
                        nextJ = j + it * dj;
                        if (nextI < 1 || nextI > N || nextJ < 1 || nextJ > M) {
                            break; //boundary over
                        }
                        // square possibility filter 1
                        int nextNum = table[nextI][nextJ];
                        curNum = curNum * 10 + nextNum;
                        if (nextNum == 2 || nextNum == 3 || nextNum == 7 || nextNum == 8) {
                            continue;
                        }
                        // square check
                        if(curNum > ans) {
                            if(IsSquare(curNum)) {
                                ans = curNum;
                            }
                        }
                        

                    }
                    


                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}