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

    bool findNode(int val, Node*& p, Node*& prev) {
        if (last == NULL) {
            return false;
        }
        
        p = last->next;
        prev = last;

        do {
            if (p->data == val) {
                return true;
            }
            prev = p;
            p = p->next;
        } while (p != last->next);

        return false;
    }

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

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << val << " inserted at the beginning." << endl;
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
        cout << val << " inserted at the end." << endl;
    }

    void insertAfter(int nodeVal, int newVal) {
        Node *p, *prev;
        if (!findNode(nodeVal, p, prev)) {
            cout << "Node " << nodeVal << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newVal);
        newNode->next = p->next;
        p->next = newNode;

        if (p == last) {
            last = newNode;
        }
        cout << newVal << " inserted after " << nodeVal << "." << endl;
    }

    void insertBefore(int nodeVal, int newVal) {
        Node *p, *prev;
        if (!findNode(nodeVal, p, prev)) {
            cout << "Node " << nodeVal << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newVal);
        newNode->next = p;
        prev->next = newNode;
        
        cout << newVal << " inserted before " << nodeVal << "." << endl;
    }

    void deleteNode(int val) {
        Node *p, *prev;
        if (!findNode(val, p, prev)) {
            cout << "Node " << val << " not found. Cannot delete." << endl;
            return;
        }

        if (p == last && p->next == p) {
            last = NULL;
        }
        else if (p == last) {
            prev->next = p->next;
            last = prev;
        }
        else {
            prev->next = p->next;
        }

        delete p;
        cout << "Node " << val << " deleted." << endl;
    }

    void searchNode(int val) {
        Node *p, *prev;
        if (findNode(val, p, prev)) {
            cout << "Node " << val << " was found in the list." << endl;
        } else {
            cout << "Node " << val << " was NOT found in the list." << endl;
        }
    }

    void display() {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;
        cout << "List (circular): Head -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(Back to Head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val, newVal;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---" << endl;
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
                cll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                cll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value of node to insert after: "; cin >> val;
                cout << "Enter new value: "; cin >> newVal;
                cll.insertAfter(val, newVal);
                break;
            case 4:
                cout << "Enter value of node to insert before: "; cin >> val;
                cout << "Enter new value: "; cin >> newVal;
                cll.insertBefore(val, newVal);
                break;
            case 5:
                cout << "Enter value to delete: "; cin >> val;
                cll.deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: "; cin >> val;
                cll.searchNode(val);
                break;
            case 7:
                cll.display();
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