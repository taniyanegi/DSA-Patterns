// code for largest BST in a binary tree
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


Node* buildTree(vector<int>& preorder){
    static int idx=-1;
    idx++;

      if(preorder[idx]==-1){
        return NULL;
      }

    Node* root=new Node(preorder[idx]);
    root->left=buildTree(preorder) ; //left
    root->right=buildTree(preorder);  //right

    return root;
}

// largest BST in a binary tree
class Info{
    public:
    int min;
    int max;
    int sz;

    Info(int min,int max,int sz){
        this->min=min;
        this->max=max;
        this->sz=sz;
    }
};

// helper function to find the largest BST in a binary tree

Info helper(Node* root){
    if(root==NULL){
        return Info(INT_MAX,INT_MIN,0);
    }

    if(root->left==NULL && root->right==NULL){
        return Info(root->data,root->data,1);
    }

    Info left=helper(root->left);
    Info right=helper(root->right);

    if(left.max<root->data && right.min>root->data){
        return Info(min(left.min,root->data),max(right.max,root->data),left.sz+right.sz+1);
    }

    return Info(INT_MIN,INT_MAX,max(left.sz,right.sz));
} 

int largestBSTinBT(Node* root){
     Info ans=helper(root);

     return ans.sz;
}

int main(){
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
     
   Node* root=buildTree(preorder);

   cout<<largestBSTinBT(root)<<endl;

    return 0;
}

