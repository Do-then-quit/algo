//
//  main.cpp
//  BJ_10828
//
//  Created by LeeMinkyo on 2020/12/31.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node()  //생성자.
    {
        this->data = 0;
        this->next = NULL;
    }
};

class Queue {
private:
    int size;
    Node* front;
    Node* back;
    
public:
    Queue()
    {
        size = 0;
        front = NULL;
        back = NULL;
    }
    int IsEmpty() {
        if (this->size == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    
    void Push(int value) {
        Node* newNode = new Node();
        
        newNode->data = value;
        if (IsEmpty() == 1) {
            front = newNode;
            back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode;
        }
        this->size++;
    }
    
    int Pop() {
        if (IsEmpty() == 1) {
            return -1;
        } else {
            this->size--;
            int tempData = front->data;
            Node* tempNode = front;
            front = front->next;
            delete tempNode;
            return tempData;
        }
    }
    
    int Size() {
        return this->size;
    }
    
    int Front() {
        if (IsEmpty() == 1) {
            return -1;
        } else {
            return this->front->data;
        }
    }
    
    int Back() {
        if (IsEmpty() == 1) {
            return -1;
        } else {
            return this->back->data;
        }
    }
    
};

int main(void) {
    Queue q;
    int n;
    int x;
    string str;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "push") {
            cin >> x;
            q.Push(x);
        } else if (str == "pop") {
            cout << q.Pop() << "\n";
        } else if (str == "size") {
            cout << q.Size() << "\n";
        } else if (str == "empty") {
            cout << q.IsEmpty() << "\n";
        } else if (str == "front") {
            cout << q.Front() << "\n";
        } else if (str == "back") {
            cout << q.Back() << "\n";
        }
    }
    
    return 0;
}

