#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) return; // not found
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) return;
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    int search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, key;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before Value\n4. Insert After Value\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n";
        cout << "8. Search Node\n9. Display List\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Enter key & value: "; cin >> key >> val; list.insertBefore(key, val); break;
            case 4: cout << "Enter key & value: "; cin >> key >> val; list.insertAfter(key, val); break;
            case 5: list.deleteFromBeginning(); break;
            case 6: list.deleteFromEnd(); break;
            case 7: cout << "Enter key: "; cin >> key; list.deleteNode(key); break;
            case 8: cout << "Enter key: "; cin >> key;
                    val = list.search(key);
                    if (val != -1) cout << "Found at position: " << val << "\n";
                    else cout << "Not Found\n";
                    break;
            case 9: list.display(); break;
        }
    } while (choice != 0);

    return 0;
}