// validate BST 
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

Node* buildBST(vector<int> &arr) {
    Node *root=NULL;
    
    for(int val:arr){
        root=insert(root,val);
    }

    return root;

}

Node* insert(Node *root, int val) {
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

bool ValidateBST(Node* root, Node* min, Node* max) {
        if(root == NULL) {
            return true;
        }

        if(min != NULL && root->data <= min->data) {
            return false;
        }

        if(max!=NULL && root->data>=max->data){
            return false;
        }

        return ValidateBST(root->left,min,root) && ValidateBST(root->right,root,max);
    }

   int main(){
     vector<int> arr={3,2,1,5,6,4};

     Node *root =  buildBST(arr);
       
       bool ans=ValidateBST(root,NULL,NULL);

       if(ans){
           cout<<"Valid BST"<<endl;
       }
       else{
           cout<<"Invalid BST"<<endl;
       }

  cout<<endl; 
  return 0;
}