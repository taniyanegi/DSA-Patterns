#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Build normal binary tree from preorder
Node* buildTree(vector<int>& preorder) {
    static int idx = -1;

    idx++;

    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

Node* successor = NULL;
bool found = false;

bool inorder(Node* root, int val) {

    if(root == NULL) {
        return false;
    }

    // Left
    if(inorder(root->left, val)) {
        return true;
    }

    // Current node
    if(found) {
        successor = root;
        return true;
    }

    if(root->data == val) {
        found = true;
    }

    // Right
    if(inorder(root->right, val)) {
        return true;
    }

    return false;
}

// inorder successor is the leftmost node in the right subtree of the given node
Node* inorderSuccessor(Node* root, int val) {

    successor = NULL;
    found = false;

    inorder(root, val);

    return successor;
}

int main() {

    vector<int> preorder = {
        1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1
    };

    Node* root = buildTree(preorder);

    Node* ans = inorderSuccessor(root, 4);

    if(ans != NULL) {
        cout << "Inorder Successor of 4 is: "
             << ans->data << endl;
    }
    else {
        cout << "Inorder Successor of 4 is NULL" << endl;
    }

    return 0;
}