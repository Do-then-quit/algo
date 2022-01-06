//
//  main.cpp
//  BJ_10866
//
//  Created by LeeMinkyo on 2021/01/02.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node()  //생성자.
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
};
//front -> -> ... back
// -> next direction
class Deck {
private:
    int size;
    Node* front;
    Node* back;
    
public:
    Deck()
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
    
    void Push_back(int value) {
        Node* newNode = new Node();
        
        newNode->data = value;
        if (IsEmpty() == 1) {
            front = newNode;
            back = newNode;
        }
        else {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
        this->size++;
    }
    void Push_front(int value) {
        Node* newNode = new Node();
        
        newNode->data = value;
        if (IsEmpty() == 1) {
            front = newNode;
            back = newNode;
        }
        else {
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        this->size++;
    }
    
    int Pop_front() {
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
    int Pop_back() {
        if (IsEmpty() == 1) {
            return -1;
        } else {
            this->size--;
            int tempData = back->data;
            Node* tempNode = back;
            back = back->prev;
            
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
    Deck d;
    int n;
    int x;
    string str;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "push_back") {
            cin >> x;
            d.Push_back(x);
        } else if (str == "push_front") {
            cin >> x;
            d.Push_front(x);
        } else if (str == "pop_back") {
            cout << d.Pop_back() << "\n";
        } else if (str == "pop_front") {
            cout << d.Pop_front() << "\n";
        } else if (str == "size") {
            cout << d.Size() << "\n";
        } else if (str == "empty") {
            cout << d.IsEmpty() << "\n";
        } else if (str == "front") {
            cout << d.Front() << "\n";
        } else if (str == "back") {
            cout << d.Back() << "\n";
        }
    }
    
    return 0;
}
