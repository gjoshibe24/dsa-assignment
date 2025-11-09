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
         cout << "Added " << val << endl;
    }

    int getSize() {
        if (last == NULL) {
            return 0;
        }

        int count = 0;
        Node* temp = last->next; 

        do {
            count++;
            temp = temp->next;
        } while (temp != last->next); 

        return count;
    }
};

int main() {
    CircularLinkedList cll;
    int val;

    cout << "--- Create Circular Linked List ---" << endl;
    cout << "Enter values to add. (Enter -1 to stop):" << endl;

    while (true) {
        cout << "Enter value: ";
        cin >> val;

        if (val == -1) {
            break; 
        }
        
        cll.insertAtEnd(val);
    }

    cout << "\n--- List Creation Finished ---" << endl;
    cout << "Size of Circular Linked List: " << cll.getSize() << endl; 

    return 0;
}