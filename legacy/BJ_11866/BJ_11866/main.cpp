//
//  main.cpp
//  BJ_11866
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
public:
    int size;
    Node* front;
    Node* back;
    
    Deck()
    {
        size = 0;
        front = NULL;
        back = NULL;
    }
    
    void Push_back(int value) {
        Node* newNode = new Node();
        
        newNode->data = value;
        if (size == 0) {
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

};

int main(void) {
    Deck d;
    int n, k;
    cin >> n;
    cin >> k;
    for (int i = 1; i <= n; i++) {
        d.Push_back(i);
    }
    d.back->next = d.front;
    d.front->prev = d.back;
    
    Node* cur;
    cur = d.front;
    cout << "<";
    while (d.size != 0) {
        for (int i = 0; i < k; i++) {
            cur = cur->next;
        }
        //prev del
        Node* temp = cur->prev;
        int temp_data = temp->data;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        d.size--;
        if (d.size == 0) {
            cout << temp_data << ">";
        } else {
            cout << temp_data << ", ";
        }
    }
    cout << "\n";
    return 0;
}

