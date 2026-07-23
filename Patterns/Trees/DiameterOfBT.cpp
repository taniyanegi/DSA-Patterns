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


// actual logic for diameter of binary tree
  // optimal approach-that gives TC-O(n) and SC-O(n)


    int ans=0;    // global variable to store the maximum diameter found so far
    
    int height(Node* root){
          if(root==NULL){
            return 0;
          }

          int leftht=height(root->left);
          int rightht=height(root->right);
          ans=max(leftht+rightht,ans);
          return max(leftht,rightht)+1;
    }



    //   // This approach give TC-O(n^2) because for each node we are calculating height of left and right subtree which is O(n) and we are doing this for each node so overall TC=O(n^2)
    // int height(Node* root){
    //       if(root==NULL){
    //         return 0;
    //       }

    //       int leftht=height(root->left);
    //       int rightht=height(root->right);

    //       return max(leftht,rightht)+1;
    // }

    // int diameterOfBinaryTree(Node* root) {
    //      if(root==NULL){
    //         return 0;
    //      }

    //      int leftDiameter=diameterOfBinaryTree(root->left);
    //      int rightDiameter=diameterOfBinaryTree(root->right);
    //      int currDiameter=height(root->left)+height(root->right);

    //      return max(currDiameter,max(leftDiameter,rightDiameter));
    // }


int main(){
    // example usage
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
     
    Node* root=buildTree(preorder);

     //code for optimal approach
    height(root);
    cout<<"Diameter of Binary Tree is "<<ans<<endl;

    //code for brute force approach
    // int diameter=diameterOfBinaryTree(root);
    // cout<<"Diameter of Binary Tree is "<<diameter<<endl;

    return 0;
}