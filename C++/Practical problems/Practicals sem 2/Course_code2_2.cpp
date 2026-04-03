#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr; 
    }
    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        cout << val << " pushed to stack.\n";
    }
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow. Nothing to pop.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from stack.\n";
        delete temp;
    }
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    cout << "--- Stack Operations ---\n";
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.peek() << "\n"; 
    s.pop();
    s.pop(); 
    return 0;
}