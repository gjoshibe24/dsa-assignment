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

    Node* findNode(int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }
        return temp;
    }

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

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            cout << val << " inserted at the end." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << val << " inserted at the end." << endl;
    }

    void insertAfter(int nodeVal, int newVal) {
        Node* p = findNode(nodeVal);
        if (p == NULL) {
            cout << "Node " << nodeVal << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newVal);
        newNode->next = p->next;
        newNode->prev = p;
        
        if (p->next != NULL) {
            p->next->prev = newNode;
        }
        p->next = newNode;
        cout << newVal << " inserted after " << nodeVal << "." << endl;
    }

    void insertBefore(int nodeVal, int newVal) {
        Node* p = findNode(nodeVal);
        if (p == NULL) {
            cout << "Node " << nodeVal << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newVal);
        newNode->next = p;
        newNode->prev = p->prev;

        if (p->prev != NULL) {
            p->prev->next = newNode;
        } else {
            head = newNode;
        }
        p->prev = newNode;
        cout << newVal << " inserted before " << nodeVal << "." << endl;
    }

    void deleteNode(int val) {
        Node* p = findNode(val);
        if (p == NULL) {
            cout << "Node " << val << " not found. Cannot delete." << endl;
            return;
        }

        if (p->prev != NULL) {
            p->prev->next = p->next;
        } else {
            head = p->next;
        }

        if (p->next != NULL) {
            p->next->prev = p->prev;
        }

        delete p;
        cout << "Node " << val << " deleted." << endl;
    }

    void searchNode(int val) {
        Node* p = findNode(val);
        if (p != NULL) {
            cout << "Node " << val << " was found in the list." << endl;
        } else {
            cout << "Node " << val << " was NOT found in the list." << endl;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "List (head to tail): NULL <-> ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val, newVal;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After a Node" << endl;
        cout << "4. Insert Before a Node" << endl;
        cout << "5. Delete a Node" << endl;
        cout << "6. Search for a Node" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                dll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                dll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value of node to insert after: "; cin >> val;
                cout << "Enter new value: "; cin >> newVal;
                dll.insertAfter(val, newVal);
                break;
            case 4:
                cout << "Enter value of node to insert before: "; cin >> val;
                cout << "Enter new value: "; cin >> newVal;
                dll.insertBefore(val, newVal);
                break;
            case 5:
                cout << "Enter value to delete: "; cin >> val;
                dll.deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: "; cin >> val;
                dll.searchNode(val);
                break;
            case 7:
                dll.display();
                break;
            case 8:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}