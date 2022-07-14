#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> v;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int shockness;
        cin >> shockness;
        v.push_back(shockness);
    }

    sort(v.begin(), v.end());

    int answer = 0;
    int countGroup = 0;

    for(int i = 0; i < N; i++)
    {
        countGroup++;
        if (v[i] <= countGroup)
        {
            // go
            answer++;
            countGroup = 0;
        }
    }

    cout << answer << endl;

    return 0;

}