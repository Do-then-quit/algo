#include <iostream>
using namespace std;
struct chunk
{
    unsigned int beforeCal;
    unsigned int r;
    unsigned int c;
};

chunk m[501][501];

int main(void) {
    int numOfMatrix;
    cin >> numOfMatrix;
    for (int i = 1; i <= numOfMatrix; i++)
    {
        unsigned int r;
        unsigned int c;
        cin >> r >> c;
        m[i][i].r = r;
        m[i][i].c = c;
        m[i][i].beforeCal = 0;
    }
    for (int i = 1; i < numOfMatrix; i++)
    {
        for(int start = 1; start + i <= numOfMatrix; start++)
        {
            int end = start + i;
            // cal
            unsigned int beforeCal = 4294967295; // unsigned int max
            unsigned int r, c;

            for (int j = start; j < end; j++) {
                unsigned int cur = 0;
                cur += m[start][j].beforeCal + m[j+1][end].beforeCal;
                cur += m[start][j].r * m[start][j].c * m[j+1][end].c;
                if (cur < beforeCal) {
                    beforeCal = cur;
                    r = m[start][j].r;
                    c = m[j+1][end].c;
                }
            }
            m[start][end].beforeCal = beforeCal;
            m[start][end].r = r;
            m[start][end].c = c;
            //cout << "cur m[" << start << "][" << end << "] value : " << beforeCal << " " << r << " " << c << endl;
        }
    }
    cout << m[1][numOfMatrix].beforeCal << endl;
    return 0;

}

