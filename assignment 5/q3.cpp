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

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    int findMiddle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow ? slow->data : -1;
    }
};

int main() {
    LinkedList list;
    list.insert(1); list.insert(2); list.insert(3);
    list.insert(4); list.insert(5);

    cout << "Middle Element: " << list.findMiddle() << endl;
    return 0;
}