// height of binary tree

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

static int idx=-1;
Node* buildTree(vector<int>& preorder){
    idx++;

      if(preorder[idx]==-1){
        return NULL;
      }

    Node* root=new Node(preorder[idx]);
    root->left=buildTree(preorder) ; //left
    root->right=buildTree(preorder);  //right

    return root;
}

int HeightOfBinaryTree(Node* root){
      if(root==NULL){
        return NULL;
      }

     int leftht=HeightOfBinaryTree(root->left);
     int rightht=HeightOfBinaryTree(root->right);

     return 1+max(leftht,rightht);
     
}

int main(){
    // example usage
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
     
    Node* root=buildTree(preorder);

    int height=HeightOfBinaryTree(root);
    cout<<"tree height is"<<height<<endl;
    return 0;
}