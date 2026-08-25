// Inorder predecessor of a node in a normal Binary Tree

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


// Global variables for inorder traversal
Node* previous = NULL;
Node* predecessor = NULL;


// Find predecessor using inorder traversal
bool inorder(Node* root, int val) {

    if(root == NULL) {
        return false;
    }

    // Left
    if(inorder(root->left, val)) {
        return true;
    }

    // Current node
    if(root->data == val) {
        predecessor = previous;
        return true;
    }

    // Current node becomes previous
    previous = root;

    // Right
    if(inorder(root->right, val)) {
        return true;
    }

    return false;
}

// inorder predecessor is the rightmost node in the left subtree of the given node
Node* inorderPredecessor(Node* root, int val) {

    previous = NULL;
    predecessor = NULL;

    inorder(root, val);

    return predecessor;
}


int main() {

    vector<int> preorder = {
        1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1
    };

    Node* root = buildTree(preorder);

    Node* ans = inorderPredecessor(root, 4);

    if(ans != NULL) {
        cout << "Inorder Predecessor of 4 is: "
             << ans->data << endl;
    }
    else {
        cout << "Inorder Predecessor of 4 is NULL" << endl;
    }

    return 0;
}