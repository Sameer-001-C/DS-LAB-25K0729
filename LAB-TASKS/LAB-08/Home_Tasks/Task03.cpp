#include <iostream>
#include <queue>
#include <algorithm>
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

void preorder(Node* r)   { if (!r) return; cout << r->data << " "; preorder(r->left); preorder(r->right); }
void inorder(Node* r)    { if (!r) return; inorder(r->left); cout << r->data << " "; inorder(r->right); }
void postorder(Node* r)  { if (!r) return; postorder(r->left); postorder(r->right); cout << r->data << " "; }
void levelorder(Node* r) {
    if (!r) return;
    queue<Node*> q;
    q.push(r);
    while (!q.empty()) {
        Node* c = q.front(); q.pop();
        cout << c->data << " ";
        if (c->left) q.push(c->left);
        if (c->right) q.push(c->right);
    }
}

int countNodes(Node* r) { return r ? 1 + countNodes(r->left) + countNodes(r->right) : 0; }
int countLeaves(Node* r) {
    if (!r) return 0;
    if (!r->left && !r->right) return 1;
    return countLeaves(r->left) + countLeaves(r->right);
}

int height(Node* r) { return r ? 1 + max(height(r->left), height(r->right)) : -1; }

bool isFull(Node* r) {
    if (!r) return true;
    if (!r->left && !r->right) return true;
    if (r->left && r->right) return isFull(r->left) && isFull(r->right);
    return false;
}

bool isComplete(Node* r) {
    if (!r) return true;
    queue<Node*> q;
    q.push(r);
    bool seenMissing = false;
    while (!q.empty()) {
        Node* c = q.front(); q.pop();
        if (c->left) {
            if (seenMissing) return false;
            q.push(c->left);
        } else seenMissing = true;
        if (c->right) {
            if (seenMissing) return false;
            q.push(c->right);
        } else seenMissing = true;
    }
    return true;
}

void destroy(Node* r) { if (!r) return; destroy(r->left); destroy(r->right); delete r; }

void analyse(const char* name, Node* root) {
    cout << "\n===== Chart " << name << " =====\n";
    cout << "Pre-order   : "; preorder(root);   cout << "\n";
    cout << "In-order    : "; inorder(root);    cout << "\n";
    cout << "Post-order  : "; postorder(root);  cout << "\n";
    cout << "Level-order : "; levelorder(root); cout << "\n";
    cout << "Nodes: " << countNodes(root)
         << "  Leaves: " << countLeaves(root)
         << "  Height: " << height(root)
         << "  Full? " << (isFull(root) ? "Yes" : "No")
         << "  Complete? " << (isComplete(root) ? "Yes" : "No") << "\n";
}

int main() {
  
    Node* A = createNode(1);
    A->left = createNode(2);
    A->right = createNode(3);
    A->left->left = createNode(4);
    A->left->right = createNode(5);
    A->right->left = createNode(6);

  
    Node* B = createNode(1);
    B->left = createNode(2);
    B->right = createNode(3);
    B->left->left = createNode(4);
    B->left->right = createNode(5);
    B->right->right = createNode(7);

  
    Node* C = createNode(1);
    C->left = createNode(2);
    C->right = createNode(3);
    C->left->left = createNode(4);
    C->left->right = createNode(5);
    C->right->left = createNode(6);
    C->right->right = createNode(7);

    analyse("A", A);
    analyse("B", B);
    analyse("C", C);

    cout << "\nSummary\nChart Nodes Leaves Height Full? Complete?\n";
    Node* charts[] = {A, B, C};
    const char* names[] = {"A", "B", "C"};
    for (int i = 0; i < 3; i++)
        cout << "  " << names[i] << "     " << countNodes(charts[i]) << "      "
             << countLeaves(charts[i]) << "      " << height(charts[i]) << "     "
             << (isFull(charts[i]) ? "Yes" : "No ") << "    "
             << (isComplete(charts[i]) ? "Yes" : "No") << "\n";

    destroy(A); destroy(B); destroy(C);
    return 0;
}
