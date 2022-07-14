#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    string s;
    cin >> s;

    int size = s.size();
    //cout << size << endl;

    int arr[20];
    for(int i = 0; i < s.size(); i++)
    {
        // int arr[i] = s[i] - '0';
        char c = s[i];
        arr[i] = atoi(&c);
        
        //cout << arr[i] << " ";
    }

    int answer = 0;

    for(int i = 0; i < s.size(); i++)
    {
        int plus = answer + arr[i];
        int multiple = answer * arr[i];

        if (plus > multiple)
        {
            answer = plus;
        }
        else 
        {
            answer = multiple;
        }
    }

    cout << answer << endl;

    return 0;
}