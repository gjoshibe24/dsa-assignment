#include <iostream>

using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(NULL), prev(NULL) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Added " << val << endl;
    }

    int getSize() {
        int count = 0;
        Node* temp = head; 
        
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    int val;

    cout << "--- Create Doubly Linked List ---" << endl;
    cout << "Enter values to add. (Enter -1 to stop):" << endl;

    while (true) {
        cout << "Enter value: ";
        cin >> val;

        if (val == -1) {
            break; 
        }
        
        dll.insertAtEnd(val);
    }

    cout << "\n--- List Creation Finished ---" << endl;
    cout << "Size of Doubly Linked List: " << dll.getSize() << endl; 

    return 0;
}