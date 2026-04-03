#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
class BinaryTree {
private:
    Node* root;
    Node* insertRecursive(Node* current, int val) {
        if (current == nullptr) {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }        if (val < current->data) {
            current->left = insertRecursive(current->left, val);
        } else {
            current->right = insertRecursive(current->right, val);
        }

        return current;
    }

    void inorderRecursive(Node* current) {
        if (current == nullptr) return;
        inorderRecursive(current->left);
        cout << current->data << " ";
        inorderRecursive(current->right);
    }
    void preorderRecursive(Node* current) {
        if (current == nullptr) return;
        cout << current->data << " ";
        preorderRecursive(current->left);
        preorderRecursive(current->right);
    }
    void postorderRecursive(Node* current) {
        if (current == nullptr) return;
        postorderRecursive(current->left);
        postorderRecursive(current->right);
        cout << current->data << " ";
    }
public:
    BinaryTree() {
        root = nullptr;
    }
    void insert(int val) {
        root = insertRecursive(root, val);
        cout << val << " inserted into the tree.\n";
    }
    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorderRecursive(root);
        cout << "\n";
    }
    void displayPreorder() {
        cout << "Preorder Traversal: ";
        preorderRecursive(root);
        cout << "\n";
    }
    void displayPostorder() {
        cout << "Postorder Traversal: ";
        postorderRecursive(root);
        cout << "\n";
    }
};
int main() {
    BinaryTree tree;
    int choice, value;
    while (true) {
        cout << "\n========== TREE MENU ==========\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. EXIT\n";
        cout << "===============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.displayInorder();
                break;
            case 3:
                tree.displayPreorder();
                break;
            case 4:
                tree.displayPostorder();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}