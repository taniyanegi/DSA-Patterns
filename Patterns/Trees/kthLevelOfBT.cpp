// print kth level of binary tree

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

void printKthLevel(Node* root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 1) {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}

int main(){
    // example usage
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
     
    Node* root=buildTree(preorder);
    printKthLevel(root, 2); // print 3rd level (0-indexed)
    return 0;
}