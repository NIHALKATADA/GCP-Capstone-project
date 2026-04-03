#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr; 
    }
    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at the beginning.\n";
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            cout << val << " inserted as the first element.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << val << " inserted at the end.\n";
    }
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from the beginning.\n";
        delete temp;
    }
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << head->data << " deleted from the list.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nullptr;
        cout << nodeToDelete->data << " deleted from the end.\n";
        delete nodeToDelete;
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display List\n";
        cout << "6. EXIT\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                list.deleteFromBeginning();
                break;
            case 4:
                list.deleteFromEnd();
                break;
            case 5:
                list.display();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}