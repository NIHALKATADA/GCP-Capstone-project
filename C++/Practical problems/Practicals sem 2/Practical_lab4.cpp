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
    void insertNode(int val) {
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
        cout << val << " inserted into the list.\n";
    }
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << val << " deleted from the list.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Value " << val << " not found in the list.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << val << " deleted from the list.\n";
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
        cout << "1. INSERT\n";
        cout << "2. DELETE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertNode(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 3:
                list.display();
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }
    return 0;
}