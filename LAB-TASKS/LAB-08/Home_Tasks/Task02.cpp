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
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}
Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

bool exists(Node* root, int key) {
    while (root) {
        if (key == root->data) return true;
        root = (key < root->data) ? root->left : root->right;
    }
    return false;
}


Node* deleteNode(Node* root, int key, bool usePred, bool verbose) {
    if (!root) return nullptr;
    if (key < root->data) {
        root->left = deleteNode(root->left, key, usePred, verbose);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key, usePred, verbose);
    } else {
        // Case 1: leaf
        if (!root->left && !root->right) {
            if (verbose) cout << "Discharge " << key << " -> LEAF\n";
            delete root;
            return nullptr;
        }
        // Case 2: one child
        if (!root->left || !root->right) {
            if (verbose) cout << "Discharge " << key << " -> ONE CHILD\n";
            Node* child = root->left ? root->left : root->right;
            delete root;
            return child;
        }
        // Case 3: two children
        if (!usePred) {
            Node* succ = findMin(root->right);
            if (verbose) cout << "Discharge " << key << " -> TWO CHILDREN (replaced by successor "
                              << succ->data << ")\n";
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data, usePred, false);
        } else {
            Node* pred = findMax(root->left);
            if (verbose) cout << "Discharge " << key << " -> TWO CHILDREN (replaced by predecessor "
                              << pred->data << ")\n";
            root->data = pred->data;
            root->left = deleteNode(root->left, pred->data, usePred, false);
        }
    }
    return root;
}

void preorder(Node* r) { if (!r) return; cout << r->data << " "; preorder(r->left); preorder(r->right); }
void inorder(Node* r)  { if (!r) return; inorder(r->left); cout << r->data << " "; inorder(r->right); }
void destroy(Node* r)  { if (!r) return; destroy(r->left); destroy(r->right); delete r; }

void show(Node* root) {
    cout << "pre-order : "; preorder(root); cout << "\n";
    cout << "in-order  : "; inorder(root);  cout << "\n";
}

int main() {
    int admit[] = {10, 6, 13, 4, 8, 11, 25, 2, 5, 7, 9, 12, 20};
    int discharge[] = {2, 11, 6, 99};

    Node* succTree = nullptr;
    Node* predTree = nullptr;
    for (int v : admit) { succTree = insert(succTree, v); predTree = insert(predTree, v); }

    cout << "===== Deletion using IN-ORDER SUCCESSOR =====\n";
    cout << "Initial\n"; show(succTree);
    for (int id : discharge) {
        cout << "\n";
        if (!exists(succTree, id)) { cout << "Discharge " << id << " -> Patient not found\n"; show(succTree); continue; }
        succTree = deleteNode(succTree, id, false, true);
        show(succTree);
    }

    cout << "\n===== BONUS: Deletion using IN-ORDER PREDECESSOR =====\n";
    cout << "Initial\n"; show(predTree);
    for (int id : discharge) {
        cout << "\n";
        if (!exists(predTree, id)) { cout << "Discharge " << id << " -> Patient not found\n"; show(predTree); continue; }
        predTree = deleteNode(predTree, id, true, true);
        show(predTree);
    }

    cout << "\n===== Comparison of final trees =====\n";
    cout << "Successor   version pre-order: "; preorder(succTree); cout << "\n";
    cout << "Predecessor version pre-order: "; preorder(predTree); cout << "\n";
    cout << "Both in-order outputs are identical (sorted), but the shapes differ:\n"
         << "the successor method pulls the node up from the right subtree,\n"
         << "the predecessor method pulls it up from the left subtree.\n";

    destroy(succTree);
    destroy(predTree);
    return 0;
}
