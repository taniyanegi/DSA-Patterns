// recover bst code
// time complexity: O(n)
// space complexity: O(h) - h is the height of the tree
// This is recursive code, we can also do it iteratively using morris traversal
#include <iostream>
#include <vector>
using namespace std;

// To find swapped nodes
Node* previous = NULL;
Node* first = NULL;
Node* second = NULL;

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

Node* insert(Node* root, int val) {

    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* BuildBST(vector<int>& arr) {

    Node* root = NULL;

    for(int val : arr) {
        root = insert(root, val);
    }

    return root;
}



void inorder(Node* root) {

    if(root == NULL) {
        return;
    }

    inorder(root->left);

    // Check for violation of sorted inorder property
    if(previous != NULL && root->data < previous->data) {

        // First violation
        if(first == NULL) {
            first = previous;
        }

        // Current node can be second
        second = root;
    }

    previous = root;

    inorder(root->right);
}

void recoverTree(Node* root) {

    inorder(root);

    // Swap the values back
    swap(first->data, second->data);
}

void printInorder(Node* root) {

    if(root == NULL) {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {

    vector<int> arr = {10, 5, 15, 2, 7, 12, 20};

    Node* root = BuildBST(arr);

    // Swapping two nodes to simulate the mistake
    swap(root->left->data, root->right->data);
    // 5 and 15 are swapped

    cout << "Before recovery: ";
    printInorder(root);
    cout << endl;

    recoverTree(root);

    cout << "After recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}