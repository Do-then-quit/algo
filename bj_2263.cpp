#include <iostream>
#include <vector>
using namespace std;

//vector<int> inOrder;
//vector<int> postOrder;
int inOrder[100001];
int postOrder[100001];
int n;
void preOrder(int, int, int, int);
int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &(inOrder[i]));
    }
    for (int i = 0; i < n; i++)
    {
        
        scanf("%d", &(postOrder[i]));
        
    }
    preOrder(0, n - 1, 0, n - 1);
    return 0;
}

void preOrder(int inA, int inB, int postA, int postB) {
    // stop condition; 
    if (inA > inB)
    {
        return;
    }
    int rootIdxPost = postB;
    int root = postOrder[rootIdxPost];
    printf("%d ", postOrder[rootIdxPost]);
    // find root in inorder;
    // print
    int rootIdxIn;
    for (int i = inA; i <= inB; i++)
    {
        if (inOrder[i] == root)
        {
            rootIdxIn = i;
            break;
        }
    }
    
    int leftInA, leftInB, rightInA, rightInB;
    int leftPostA, leftPostB, rightPostA, rightPostB;
    leftInA = inA; leftInB = rootIdxIn - 1;
    rightInA = rootIdxIn + 1; rightInB = inB;

    rightPostB = rootIdxPost - 1;
    rightPostA = rightPostB - (rightInB - rightInA);
    leftPostB = rightPostA - 1;
    leftPostA = leftPostB - (leftInB - leftInA);

    preOrder(leftInA, leftInB, leftPostA, leftPostB);
    preOrder(rightInA, rightInB, rightPostA, rightPostB);
    
}