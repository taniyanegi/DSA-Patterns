// inorder predecessor and successor in BST

#include<iostream>
#include<bits/stdc++.h>

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

Node* insert(Node* root, int val) {
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

Node *buildBST(vector<int>& arr) {
    Node* root = NULL;

    for (int val : arr) {
        root = insert(root, val);
    }

    return root;
}

// predecessor
Node* RightMostInLeftSubtree(Node* root){
        Node* ans=NULL;

         while(root!=NULL){
            ans=root;
            root=root->right;
         }
         return ans;
}

// successor
Node* LeftMostInRightSubtree(Node* root){
         Node* ans=NULL;

         while(root!=NULL){
            ans=root;
            root=root->left;
         }
         return ans;
}

vector<int> getPredSucc(Node* root,int key){
     Node* curr=root;
     Node* pred=NULL;
     Node* succ=NULL;
     
     while(curr!=NULL){
            if(key<curr->data){
                succ=curr;
                curr=curr->left;
            }
            else if(key>curr->data){
                pred=curr;
                curr=curr->right;
            }
            else{
                // key found
                // predecessor
                if(curr->left!=NULL){
                    pred=RightMostInLeftSubtree(curr->left);
                }
                
                // successor
                if(curr->right!=NULL){
                     succ=LeftMostInRightSubtree(curr->right);
                }
                
                break; // exit the loop after finding the key
            } 
     }
     return {pred->data,succ->data};
}

int main(){
      vector<int> arr = {8, 5, 3, 6, 10, 9, 12};

    Node* root = buildBST(arr);

    int key = 8;

    vector<int> ans = getPredSucc(root, key);

    cout << "Predecessor = " << ans[0] << endl;
    cout << "Successor = " << ans[1] << endl;

    return 0;
}