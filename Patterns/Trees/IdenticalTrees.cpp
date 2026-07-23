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

 bool isSameTree(Node* p, Node* q) {
          if(p==NULL || q==NULL){
            return  (p==q); // return true only when both are null
          }

          bool isleftSame=isSameTree(p->left,q->left);
          bool isrightSame=isSameTree(p->right,q->right);

          return ( isleftSame && isrightSame && (p->data==q->data));

    }

int main(){
    // example usage
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
     
    Node* root=buildTree(preorder);
     
    vector<int> preorder2={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
    Node* root2=buildTree(preorder2);
     
    bool result=isSameTree(root, root2);
    cout<<"Trees are identical: "<<result<<endl;
}