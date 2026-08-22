// LCA of a Binary Search Tree (BST)
#include<iostream>
#include<vector>

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

Node* buildTree(vector<int>& preorder, int& idx) {
    if (idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    idx++;
    root->left = buildTree(preorder, idx);
    idx++;
    root->right = buildTree(preorder, idx);

    return root;
}

// time complexity- Worst case: O(h) where h is the height of the tree
// balanced tree: O(log n) where n is the number of nodes in the tree
   Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
             if(root==NULL){
                return NULL;
             }

             if(root->data>p->data && root->data>q->data){
                 return lowestCommonAncestor(root->left,p,q);
             }

             else if(root->data<p->data && root->data<q->data){
                 return lowestCommonAncestor(root->right,p,q);
             }
             
             else{
                return root;
             }
    }


    int main(){
        // example usage
        vector<int> preorder={5,3,2,-1,-1,4,-1,-1,7,6,-1,-1,8,-1,-1};
        int idx=0;
        Node* root=buildTree(preorder,idx);
        
        Node *ans=lowestCommonAncestor(root,new Node(2),new Node(4));
          if(ans!=NULL){
            cout<<"LCA: "<<ans->data<<endl;
          }
          else{
            cout<<"LCA not found"<<endl;
          }
    }