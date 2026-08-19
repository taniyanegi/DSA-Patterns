// flatten binary tree to linked list
#include<bits/stdc++.h>
#include <iostream>

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

Node* buildTree(vector<int>& preorder) {
    static int idx = -1;
    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;

}


 Node* nextRight=NULL;
    void flatten(Node* root) {
         if(root==NULL){
            return;
         }

         flatten(root->right);
         flatten(root->left);

         root->left=NULL;
         root->right=nextRight;
         nextRight=root;
    }

    int main() {
        vector<int> preorder = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, -1};
        Node* root = buildTree(preorder);

        flatten(root);

        // Print the flattened linked list
        Node* curr = root;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        cout << endl;

        return 0;
    }