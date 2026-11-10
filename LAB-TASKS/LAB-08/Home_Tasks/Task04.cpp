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

int countNodes(Node* r) { return r ? 1 + countNodes(r->left) + countNodes(r->right) : 0; }


void rangeSearch(Node* root, int low, int high, int& visited) {
    if (!root) return;
    visited++;
    if (root->data > low)
        rangeSearch(root->left, low, high, visited);
    if (root->data >= low && root->data <= high)
        cout << root->data << " ";
    if (root->data < high)
        rangeSearch(root->right, low, high, visited);
}

Node* findMin(Node* r) { while (r && r->left)  r = r->left;  return r; }
Node* findMax(Node* r) { while (r && r->right) r = r->right; return r; }



Node* floorPrice(Node* root, int x) {
    Node* best = nullptr;
    while (root) {
        if (root->data == x) return root;
        if (root->data < x) { best = root; root = root->right; }
        else root = root->left;
    }
    return best;
}



Node* ceilPrice(Node* root, int x) {
    Node* best = nullptr;
    while (root) {
        if (root->data == x) return root;
        if (root->data > x) { best = root; root = root->left; }
        else root = root->right;
    }
    return best;
}

void printResult(Node* n) {
    if (n) cout << n->data; else cout << "None";
}

void destroy(Node* r) { if (!r) return; destroy(r->left); destroy(r->right); delete r; }

int main() {
    int prices[] = {1500, 800, 2500, 500, 1000, 2000, 3500, 750, 1200, 3000};
    Node* root = nullptr;
    for (int p : prices) root = insert(root, p);

    int low = 1000, high = 2500, visited = 0;
    cout << "Range [" << low << ", " << high << "] : ";
    rangeSearch(root, low, high, visited);
    cout << "\n";
    cout << "Nodes visited by rangeSearch: " << visited
         << " out of " << countNodes(root) << " total nodes\n";

    cout << "Cheapest : " << findMin(root)->data << "\n";
    cout << "Most expensive : " << findMax(root)->data << "\n";

    cout << "Floor(1800) : "; printResult(floorPrice(root, 1800));
    cout << "   Ceil(1800) : "; printResult(ceilPrice(root, 1800));
    cout << "\n";
    cout << "Floor(400) : ";  printResult(floorPrice(root, 400));
    cout << "   Ceil(3600) : "; printResult(ceilPrice(root, 3600));
    cout << "\n";

    destroy(root);
    return 0;
}
