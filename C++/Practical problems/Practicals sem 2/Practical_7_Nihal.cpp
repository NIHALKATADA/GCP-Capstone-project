#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BST {
private:
    Node* root;
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    Node* insertRecursive(Node* node, int val) {
        if (node == nullptr) return new Node(val);
        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }
        return node;
    }
    Node* deleteRecursive(Node* node, int val) {
        if (node == nullptr) return node;

        if (val < node->data) {
            node->left = deleteRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = deleteRecursive(node->right, val);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data);
        }
        return node;
    }
    void inorderRecursive(Node* node) {
        if (node == nullptr) return;
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }
public:
    BST() { root = nullptr; }

    void insert(int val) {
        root = insertRecursive(root, val);
        cout << val << " inserted.\n";
    }
    void remove(int val) {
        root = deleteRecursive(root, val);
        cout << "Attempted to delete " << val << ".\n";
    }
    bool search(int val) {
        Node* current = root;
        while (current != nullptr) {
            if (current->data == val) return true;
            current = (val < current->data) ? current->left : current->right;
        }
        return false;
    }
    void display() {
        cout << "Tree (Inorder): ";
        inorderRecursive(root);
        cout << "\n";
    }
};
int main() {
    BST tree;
    int choice, value;
    while (true) {
        cout << "\n1. Insert  2. Delete  3. Search  4. Display  5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cin >> value; 
                tree.insert(value); 
                break;
            case 2: 
                cin >> value; 
                tree.remove(value); 
                break;
            case 3: 
                cin >> value; 
                if (tree.search(value)) cout << value << " found in the tree.\n";
                else cout << value << " not found.\n";
                break;
            case 4: 
                tree.display(); 
                break;
            case 5: 
                return 0;
            default: 
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}