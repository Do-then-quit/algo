#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    string s;
    cin >> s;
    int col = s[0] - 'a' + 1;
    int row = s[1] - '1' + 1;

    int dc[8] = {-2, -2, -1, 1, 2, 2, -1, 1};   //col
    int dr[8] = {-1, 1, -2, -2, -1, 1, 2, 2};   //row
    int answer = 0;
    for (int i = 0; i < 8; i++)
    {
        int nextC = col + dc[i];
        int nextR = row + dr[i];
        if (nextC < 1 || 8 < nextC || nextR < 1 || 8 < nextR)
        {
            continue;
        }
        answer++;
    }
    cout << answer << endl;
    return 0;
}