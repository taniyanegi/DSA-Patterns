// min dist bewtween two nodes in BST
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


   
    int minDiffInBST(Node* root) {
        Node * prev=NULL;
         if(root==NULL){
            return INT_MAX;
         } 

         int ans=INT_MAX;

         if(root->left!=NULL){
              int leftMin=minDiffInBST(root->left);
              ans=min(ans,leftMin);
         }  

           if(prev!=NULL){
             ans=min(ans,root->data-prev->data);
           }

           prev=root;

             if(root->right!=NULL){
              int rightMin=minDiffInBST(root->right);
              ans=min(ans,rightMin);
         } 
     return ans;
    } 

    int main(){
          vector<int> arr={4,2,6,1,3};
          Node *root =  buildBST(arr);

            int ans=minDiffInBST(root);
            cout<<ans<<endl;
    }


    