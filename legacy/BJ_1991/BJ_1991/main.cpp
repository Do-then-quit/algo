//
//  main.cpp
//  BJ_1991
//
//  Created by LeeMinkyo on 2021/02/03.
// tree implement!

#include <iostream>
#include <queue>

using namespace std;
struct node {
    char index;
    node* leftNode = NULL;
    node* rightNode = NULL;
};

void preOrder(node* ptr) {
    if (ptr) {
        cout << ptr->index;
        preOrder(ptr->leftNode);
        preOrder(ptr->rightNode);
    }
}

void postOrder(node* ptr) {
    if (ptr) {
        postOrder(ptr->leftNode);
        postOrder(ptr->rightNode);
        cout << ptr->index;
    }
}

void inOrder(node* ptr) {
    if (ptr) {
        inOrder(ptr->leftNode);
        cout << ptr->index;
        inOrder(ptr->rightNode);
    }
}

int main() {
    int N;
    cin >> N;
    node* top;
    for (int i = 0; i < N; i++) {
        char root, leftChild, rightChild;
        cin >> root >> leftChild >> rightChild;
        node* cur;
        if (root == 'A') {
            cur = new node;
            cur->index = root;
            top = cur;
        } else {
            //tree search.
            queue<node*> q;
            q.push(top);
            while (q.empty() != true) {
                cur = q.front();
                q.pop();
                if (cur->index == root) {
                    break;
                }
                
                if (cur->leftNode != NULL) {
                    q.push(cur->leftNode);
                }
                if (cur->rightNode != NULL) {
                    q.push(cur->rightNode);
                }
            }
            // cur == root;
        }
        
        if (leftChild != '.') {
            node* newNode = new node;
            newNode->index = leftChild;
            cur->leftNode = newNode;
        }
        if (rightChild != '.') {
            node* newNode = new node;
            newNode->index = rightChild;
            cur->rightNode = newNode;
        }
    }
    preOrder(top);
    cout << "\n";
    inOrder(top);
    cout << "\n";
    postOrder(top);
    cout << "\n";
    
    return 0;
}
