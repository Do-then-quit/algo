#include <iostream>
#include <stack>
#include <string>

using namespace std;

// lparen, rparen, plus, minus, times, divide, eos
int isp[] = {0, 19, 12, 12, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 0};
#define lparen 0
#define rparen 1
#define plus 2
#define minus 3
#define times 4
#define divide 5
#define eos 6

int getToken(char input) {
    switch (input) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case ' ': return eos;
        case '\n': return eos;
        case '\0': return eos;
        default : return -1;
    }
}

int main(void) {
    stack<char> s;
    s.push(' ');
    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if (getToken(input[i]) == -1)
        {
            printf("%c", input[i]);
        } else if (getToken(input[i]) == rparen) {
            while(getToken(s.top()) != lparen) {
                printf("%c", s.top());
                s.pop();
            }
            s.pop(); // lparen pop;
        } else {
            while(isp[getToken( s.top() )] >= icp[getToken(input[i])]) {
                printf("%c", s.top());
                s.pop();
            }
            s.push(input[i]);
        }
        
    }
    while (s.top() != ' ')
    {
        printf("%c", s.top());
        s.pop();
    }
    printf("\n");
    return 0;

}