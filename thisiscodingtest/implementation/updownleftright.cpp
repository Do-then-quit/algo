#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    int N;
    cin >> N;
    cin.ignore(256, '\n');
    // getline 전에 cin.ignore() 를 통해서 버퍼를 비워주자.
    string plan;
    getline(cin, plan);

    int x = 1;
    int y = 1;
    for (int i = 0; i < plan.size(); i++)
    {
        if (plan[i] == ' ') {
            continue;
        }

        if (plan[i] == 'L')
        {
            if (1 <= y-1 && y-1 <= N)
            {
                y = y - 1;
            }
        } else if (plan[i] == 'R')
        {
            if (1 <= y+1 && y+1 <= N)
            {
                y = y + 1;
            }
        } else if (plan[i] == 'U')
        {
            if (1 <= x - 1 && x-1 <= N)
            {
                x = x - 1;
            }
        } else if (plan[i] == 'D')
        {
            if (1 <= x+1 && x+1 <= N)
            {
                x = x+1;
            }
        }
        //cout << plan[i] << endl;
    }
    cout << x << " " << y << endl;

    return 0;
}