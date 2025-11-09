#include <iostream>

using namespace std;

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };

    Node* last;

public:
    CircularLinkedList() : last(NULL) {}

    ~CircularLinkedList() {
        if (last == NULL) return;

        Node* head = last->next;
        last->next = NULL; 
        
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (last == NULL) { 
            last = newNode;
            last->next = last; 
        } else {
            newNode->next = last->next; 
            last->next = newNode; 
            last = newNode; 
        }
    }

    void displayAndRepeatHead() {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next); 

        cout << last->next->data << endl;
    }
};


int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);

    cout << "Input: 20 -> 100 -> 40 -> 80 -> 60" << endl;
    cout << "Output: ";
    cll.displayAndRepeatHead();

    return 0;
}