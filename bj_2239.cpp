#include <iostream>

using namespace std;
int board[9][9];
bool isInput[9][9];

bool RowCheck(int target, int i, int j);
bool ColCheck(int, int, int);
bool SecCheck(int, int, int);
int Check(int start, int i, int j);

int main(void) {
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%1d", &(board[i][j]));
            if (board[i][j] == 0)
            {
                isInput[i][j] = false;
            } else {
                isInput[i][j] = true;
            }
            
        }
    }

    int temp = 0;
    bool isForward = true;
    while (0 <= temp && temp < 81)
    {
        int i = temp / 9;
        int j = temp % 9;
        if (isInput[i][j])
        {
            if (isForward)
            {
                temp++;
            } else {
                temp--;
            }
            
            continue;
        }

        int check = Check(board[i][j] + 1, i, j);

        if (check == -1)
        {
            // no possibility go back.
            board[i][j] = 0;
            temp--;
            isForward = false;
            continue;
        } else {
            board[i][j] = check;
            temp++;
            isForward = true;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d", board[i][j]);
        }
        printf("\n");
        
    }
    
    

    return 0;
    
}

bool RowCheck(int target, int i, int j) {
    for (int k = 0; k < 9; k++)
    {
        // if (k == j)
        // {
        //     continue;
        // }
        if (board[i][k] == target)
        {
            return false;
        }
    }
    return true;
}

bool ColCheck(int target, int i, int j) {
    for (int k = 0; k < 9; k++)
    {
        // if (k == j)
        // {
        //     continue;
        // }
        if (board[k][j] == target)
        {
            return false;
        }
    }
    return true;
}

bool SecCheck(int target, int i, int j) {
    int tempi = (i / 3) * 3;
    int tempj = (j / 3) * 3;

    for (int iSec = 0; iSec < 3; iSec++)
    {
        for (int jSec = 0; jSec < 3; jSec++)
        {
            if (board[tempi+iSec][tempj+jSec] == target)
            {
                return false;
            }
        }
    }
    
    return true;
}

int Check(int start, int i, int j) {
    for (int temp = start; temp <= 9 ; temp++)
    {
        if (ColCheck(temp, i, j) && RowCheck(temp, i, j) && SecCheck(temp, i, j))
        {
            // pass
            return temp;
        }
    }
    return -1;
    
}