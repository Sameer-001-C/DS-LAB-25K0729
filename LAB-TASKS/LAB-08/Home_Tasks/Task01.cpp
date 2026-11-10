#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int v) {
    Node* n = new Node;
    n->data = v;
    n->left = n->right = nullptr;
    return n;
}

Node* insert(Node* root, int v) {
    if (!root) return createNode(v);
    if (v < root->data) root->left = insert(root->left, v);
    else if (v > root->data) root->right = insert(root->right, v);
    else cout << "Duplicate roll number " << v << " ignored.\n";
    return root;
}

void search(Node* root, int key) {
    int comparisons = 0;
    Node* cur = root;
    cout << "Search " << key << " : ";
    while (cur) {
        comparisons++;
        cout << cur->data;
        if (key == cur->data) { cout << " FOUND  (" << comparisons << " comparisons)\n"; return; }
        cur = (key < cur->data) ? cur->left : cur->right;
        if (cur) cout << " -> ";
    }
    cout << " NOT FOUND  (" << comparisons << " comparisons)\n";
    if (comparisons == 0) cout << "(tree is empty)\n";
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void destroy(Node* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int choice, x;
    do {
        cout << "\n--- University Admission Portal ---\n"
             << "1) Register applicant\n2) Search applicant\n"
             << "3) Display sorted list\n4) Exit\nChoice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
        case 1:
            cout << "Enter roll number: "; cin >> x;
            root = insert(root, x);
            break;
        case 2:
            cout << "Enter roll number to search: "; cin >> x;
            search(root, x);
            break;
        case 3:
            cout << "Sorted list : ";
            inorder(root);
            cout << "\n";
            break;
        case 4: cout << "Goodbye.\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    destroy(root);

    
    return 0;
}
