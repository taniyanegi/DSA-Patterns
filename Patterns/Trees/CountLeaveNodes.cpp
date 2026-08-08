
// count leaf nodes in a binary tree

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



int countLeaves(Node* root) {
        // write code here
          if(root==NULL){
              return 0;
          }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int leftCount=countLeaves(root->left);
        int rightCount=countLeaves(root->right);
        
        return leftCount+rightCount;
    }


    int main(){
        
        // example usage
        vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
         
        Node* root=buildTree(preorder);

        int Total_Leaves=countLeaves(root);
        cout<<"total leaves are "<<Total_Leaves<<endl;
        return 0;
    }

