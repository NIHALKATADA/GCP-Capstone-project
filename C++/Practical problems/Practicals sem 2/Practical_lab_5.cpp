#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next, *prev;
};

class DoublyLinkedList {
private:
    Node *head, *tail;
public:
    DoublyLinkedList() { 
        head = tail = nullptr; 
    }
    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            head = newNode;
        }
        cout << val << " inserted at the beginning.\n";
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << val << " inserted at the end.\n";
    }
    void insertAtPosition(int val, int pos) {
        if (pos <= 1) { 
            insertAtBeginning(val); 
            return; 
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) { 
            insertAtEnd(val); 
            return; 
        }
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << val << " inserted at position " << pos << ".\n";
    }
    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        cout << temp->data << " deleted.\n";
        delete temp;
    }

    void deleteFromEnd() {
        if (tail == nullptr) return;

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        cout << temp->data << " deleted.\n";
        delete temp;
    }

    void deleteFromPosition(int pos) {
        if (pos <= 1) { 
            deleteFromBeginning(); 
            return; 
        }

        Node* temp = head;
        for (int i = 1; i < pos && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return;
        if (temp == tail) { 
            deleteFromEnd(); 
            return; 
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << temp->data << " deleted.\n";
        delete temp;
    }

    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value, pos;

    while (true) {
        cout << "\n1.Ins-Beg 2.Ins-End 3.Ins-Pos 4.Del-Beg 5.Del-End 6.Del-Pos 7.Disp 8.Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: cin >> value; dll.insertAtBeginning(value); break;
            case 2: cin >> value; dll.insertAtEnd(value); break;
            case 3: cin >> value >> pos; dll.insertAtPosition(value, pos); break;
            case 4: dll.deleteFromBeginning(); break;
            case 5: dll.deleteFromEnd(); break;
            case 6: cin >> pos; dll.deleteFromPosition(pos); break;
            case 7: dll.display(); break;
            case 8: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
    return 0;
}