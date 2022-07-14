#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> v;
    vector<bool> isDepart;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int shockness;
        cin >> shockness;
        v.push_back(shockness);
        isDepart.push_back(false);
    }

    sort(v.begin(), v.end());

    int answer = 0;

    for(int i = 0; i < N; i++)
    {
        int nakamaMin = i - (v[i] - 1);
        if (nakamaMin < 0) 
        {
            continue;
        }

        if (isDepart[nakamaMin] == false)
        {
            for (int j = nakamaMin; j <= i; j++)
            {
                isDepart[j] = true;
            }
            answer++;
        }
    }

    cout << answer << endl;

    return 0;

}