#include <iostream>
#include <climits>
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


bool isBST(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}


bool inorderSuccessor(Node* root, int key, int& result) {
    bool found = false;
    while (root) {
        if (root->data > key) { result = root->data; found = true; root = root->left; }
        else root = root->right;
    }
    return found;
}



bool kthHelper(Node* root, int k, int& count, int& result) {
    if (!root) return false;
    if (kthHelper(root->left, k, count, result)) return true;
    if (++count == k) { result = root->data; return true; }
    return kthHelper(root->right, k, count, result);
}

void kthSmallest(Node* root, int k) {
    int count = 0, result = 0;
    const char* suf = "th";
    if (k % 100 < 11 || k % 100 > 13) {
        if (k % 10 == 1) suf = "st"; else if (k % 10 == 2) suf = "nd"; else if (k % 10 == 3) suf = "rd";
    }
    cout << k << suf << " smallest = ";
    if (k >= 1 && kthHelper(root, k, count, result)) cout << result;
    else cout << "Out of range";
    cout << "\n";
}

void successorQuery(Node* root, int key) {
    int res;
    cout << "Successor(" << key << ") = ";
    if (inorderSuccessor(root, key, res)) cout << res; else cout << "None";
    cout << "\n";
}

void destroy(Node* r) { if (!r) return; destroy(r->left); destroy(r->right); delete r; }

int main() {

  
    Node* A = createNode(50);
    A->left = createNode(30);
    A->right = createNode(70);
    A->left->left = createNode(20);
    A->left->right = createNode(40);
    A->right->left = createNode(60);
    A->right->right = createNode(80);

    Node* B = createNode(50);
    B->left = createNode(30);
    B->right = createNode(70);
    B->left->left = createNode(20);
    B->left->right = createNode(60);  
    B->right->left = createNode(40);  
    B->right->right = createNode(80);

    bool validA = isBST(A, LLONG_MIN, LLONG_MAX);
    bool validB = isBST(B, LLONG_MIN, LLONG_MAX);

    cout << "Tree A : " << (validA ? "VALID BST" : "CORRUPTED") << "\n";
    cout << "Tree B : " << (validB ? "VALID BST"
            : "CORRUPTED (60 sits in the left subtree of 50 but is larger than 50)") << "\n";

    if (validA) {
        cout << "\nOn Tree A:\n";
        successorQuery(A, 40);
        successorQuery(A, 60);
        successorQuery(A, 30);
        successorQuery(A, 80);
        kthSmallest(A, 3);
        kthSmallest(A, 7);
        kthSmallest(A, 8);
    }
    if (validB) {
        cout << "\nOn Tree B:\n";
        successorQuery(B, 40);
        kthSmallest(B, 3);
    }



    destroy(A);
    destroy(B);
    return 0;
}
