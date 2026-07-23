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

//main logic

 // to check each and every value after getting same node
    bool isIdentical(Node* root, Node* subRoot){
           if(root==NULL || subRoot==NULL){
               return root==subRoot ; 
           }
return (root->data==subRoot->data 
      && isIdentical(root->left,subRoot->left) 
      && isIdentical(root->right,subRoot->right));
    }

// for searching same val
    bool isSubtree(Node* root, Node* subRoot) {
        if(root==NULL || subRoot==NULL){
               return root==subRoot ;    // return false when any one is NULL and true when both are NULL
        }
        // first check root of both tree if thrie value matches and recursive call also trturn true then return true

        if(root->data==subRoot->data  &&  isIdentical(root,subRoot)){
            return true;
        }

return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }

int main(){
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
    Node* root=buildTree(preorder);

    vector<int> preorder2={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
    Node* root2=buildTree(preorder2);

    bool result=isSubtree(root, root2);
    cout<<"Is subtree: "<<result<<endl;
    }