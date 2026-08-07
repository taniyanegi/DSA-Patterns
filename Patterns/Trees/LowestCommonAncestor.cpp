// lowest common ancestor of binary tree

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
Node* LowestCommonAncestor(Node* root, Node* p, Node* q) {
           if(root==NULL){
            return NULL;
           }

           if(root->data==p->data || root->data==q->data){
            return root;
           }

           Node* leftLCA=LowestCommonAncestor(root->left,p,q);
           Node* rightLCA=LowestCommonAncestor(root->right,p,q);

           if(leftLCA && rightLCA){
            return root;
           }

           else if(leftLCA!=NULL){
               return leftLCA;
           }
           else{
            return rightLCA;
           }
}
int main(){
    // example usage
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
     
    Node* root=buildTree(preorder);
    
     
      Node *ans=LowestCommonAncestor(root,new Node(3),new Node(4));
      cout<<"Lowest Common Ancestor of 4 and 3 is: "<<ans->data<<endl;

    return 0;
}  