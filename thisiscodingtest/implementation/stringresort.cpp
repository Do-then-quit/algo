#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(void)
{
    string ans;
    string input;
    int sumOfNum = 0;
    bool isNum = false;

    cin >> input;
    
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            ans.push_back(input[i]);
        } else
        {
            isNum = true;
            sumOfNum += input[i] - '0';
        }
    }
    sort(ans.begin(), ans.end());
    // 숫자가 있었는지가 또 중요하네요.
    if (isNum) 
    {
        cout << ans << sumOfNum << endl;
    } else 
    {
        cout << ans << endl;
    }
    

    return 0;

}