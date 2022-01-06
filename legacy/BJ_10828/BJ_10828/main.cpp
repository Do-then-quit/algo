//
//  main.cpp
//  BJ_10828
//
//  Created by LeeMinkyo on 2020/12/31.
//

#include <iostream>
using namespace std;
// class를 만들어보는 좋은 기회였다. 구조를 조금더 이해할수 있지않았을까. 링크드 리스트도 조금이나마 복습.
class Node {
public:
    int data;
    Node* next;
    Node()  //생성자.
    {
        this->data = 0;
        this->data = NULL;
    }
};

class Stack {
private:
    int size;
    Node* top;
public:
    Stack()
    {
        size = 0;
        top = NULL;
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
        this->size++;
        
        if (IsEmpty() == 1) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }
    
    int Pop() {
        if (IsEmpty() == 1) {
            return -1;
        } else {
            this->size--;
            int tempData = top->data;
            Node* tempNode = top;
            top = top->next;
            delete tempNode;
            return tempData;
        }
    }
    
    int Size() {
        return this->size;
    }
    
    int Top() {
        if (IsEmpty() == 1) {
            return -1;
        } else {
            return this->top->data;
        }
    }
    
};

int main(void) {
    Stack s;
    int n;
    int x;
    string str;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "push") {
            cin >> x;
            s.Push(x);
        } else if (str == "pop") {
            cout << s.Pop() << "\n";
        } else if (str == "size") {
            cout << s.Size() << "\n";
        } else if (str == "empty") {
            cout << s.IsEmpty() << "\n";
        } else if (str == "top") {
            cout << s.Top() << "\n";
        }
    }
    
    return 0;
}
