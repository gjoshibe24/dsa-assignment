#include <iostream>
#include <string>

using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        char data;
        Node* next;
        Node* prev;
        Node(char val) : data(val), next(NULL), prev(NULL) {}
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

    void insertAtEnd(char val) {
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
    }

    bool isPalindrome() {
        if (head == NULL) {
            return true;
        }

        Node* first = head;
        Node* last = head;

        while (last->next != NULL) {
            last = last->next;
        }

        while (first != last && first->prev != last) {
            if (first->data != last->data) {
                return false;
            }
            first = first->next;
            last = last->prev;
        }

        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    string input;

    cout << "Enter a string to check: ";
    cin >> input;

    for (char c : input) {
        dll.insertAtEnd(c);
    }

    if (dll.isPalindrome()) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is NOT a palindrome." << endl;
    }

    return 0;
}