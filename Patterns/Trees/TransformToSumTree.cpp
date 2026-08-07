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

static int idx = -1;

// Build tree from preorder traversal
Node* buildTree(vector<int>& preorder) {

    idx++;

    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// Convert Binary Tree to Sum Tree
int sumTree(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    int oldValue = root->data;

    // Store sum of left and right subtree
    root->data = leftSum + rightSum;

    // Return original subtree sum
    return oldValue + root->data;
}

// Preorder Traversal
void preorder(Node* root) {

    if(root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

int main() {

    vector<int> preorderArray = { 1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorderArray);

    cout << "Preorder before Sum Tree:\n";
    preorder(root);

    cout << "\n";

    sumTree(root);

    cout << "Preorder after Sum Tree:\n";
    preorder(root);

    return 0;
}