// find all paths from root to leaf in a binary tree

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


// time complexity: O(n) where n is the number of nodes in the binary tree

void allPaths(Node* root,string path, vector<string> &ans){
          if(root==NULL){
            return;
          }
          
          if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
          }

          if(root->left){
            allPaths(root->left,path+"->"+to_string(root->left->data),ans);
          }

           if(root->right){
            allPaths(root->right,path+"->"+to_string(root->right->data),ans);
          }
    }

    int main(){
        
        // example usage
        vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
         
        Node* root=buildTree(preorder);
        vector<string> ans;
        allPaths(root,to_string(root->data),ans);
        
        for(auto path:ans){
            cout<<path<<endl;
        }
    }