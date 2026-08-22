// preorder to BST 
#include <iostream>
#include <vector>
#include <climits>

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

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// takes O(n*n) - in worst case - when the tree is skewed
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

// another approach - takes O(n) time and O(n) space
Node* insertOptimized(vector<int>& preorder, int &idx, int upperBound) {

           if(idx>=preorder.size() || preorder[idx]>upperBound){
            return NULL;
           }


         Node *root=new Node(preorder[idx++]);

        root->left = insertOptimized(preorder, idx, root->data); // left
        
        root->right =  insertOptimized(preorder, idx, upperBound); //right
         
         return root;
    }


int main(){
    vector<int> preorder={8,5,1,7,10,12};
    Node* root=NULL;
    
    // Approach 1 - O(n*n)
    for(int i=0;i<preorder.size();i++){
        root=insert(root,preorder[i]);
    }


    // Approach 2 - O(n)
    int idx=0;
    Node* root2=insertOptimized(preorder,idx,INT_MAX);

    // Print the inorder traversal of the BST
    cout << "Inorder traversal of the BST: ";   
    inorder(root2);
    return 0;
}


