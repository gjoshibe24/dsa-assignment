#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(NULL) {}

    ~LinkedList() {
    }

    bool isCircular() {
        if (head == NULL) {
            return false;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    LinkedList list;

    list.head = new Node(2);
    Node* node4 = new Node(4);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node5 = new Node(5);

    list.head->next = node4;
    node4->next = node6;
    node6->next = node7;
    node7->next = node5;

    node5->next = list.head; 

    if (list.isCircular()) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }

    return 0;
}