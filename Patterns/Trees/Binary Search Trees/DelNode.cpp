// delete node in a BST
// implemntation of binary search tree
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

Node *insert(Node *root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node *buildBST(vector<int> &arr) {
    Node *root=NULL;
    
    for(int val:arr){
        root=insert(root,val);
    }

    return root;
}

 
Node *deleteNode(Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 

    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 

    else {
        // key==root->data
        if (root->left == NULL && root->right == NULL) {
            // Case 1: Node is a leaf - no child
            delete root;
            return NULL;
        } 
         // Case 2: Node has only one child 
        else if (root->left == NULL) {
            //Node has only right child
            Node *temp = root->right;
            delete root;
            return temp;
        }
         else if (root->right == NULL) {
            // Node has only left child
            Node *temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Node has 2 children
        else {
            Node *Inordersuccessor = root->right;

            // Find the inorder successor (left most node in the right subtree)
            while (Inordersuccessor->left != NULL) {
                Inordersuccessor = Inordersuccessor->left;
            }
            root->data = Inordersuccessor->data; // Replace with successor's value
            root->right = deleteNode(root->right, Inordersuccessor->data); // Delete successor
        }
    }

    return root;
}


// inorder traversal of BST
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
vector<int> arr={3,2,1,5,6,4};

  Node *root =  buildBST(arr);
  
   // delete node with value 5
    root = deleteNode(root, 5);

    // Print the inorder traversal of the modified BST
    cout << "Inorder traversal after deleting 5: ";
    inorder(root);
    cout << endl;

    // delete node with value 3
    root = deleteNode(root, 3);
      inorder(root);
    cout << endl;

    //delete node with value 4
     root = deleteNode(root, 4);
      inorder(root);
    cout << endl;
  return 0;
}