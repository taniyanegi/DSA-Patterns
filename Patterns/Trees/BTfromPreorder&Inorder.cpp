#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(vector<int>& inorder,int left,int right,int val){

    for(int i=left;i<=right;i++){

        if(inorder[i]==val)
            return i;
    }

    return -1;
}

Node* helper(vector<int>& preorder,
             vector<int>& inorder,
             int &preIdx,
             int left,
             int right){

    if(left>right)
        return NULL;

    Node* root=new Node(preorder[preIdx]);

    int InIdx=search(inorder,left,right,preorder[preIdx]);

    preIdx++;

    root->left=helper(preorder,inorder,
                      preIdx,left,InIdx-1);

    root->right=helper(preorder,inorder,
                       preIdx,InIdx+1,right);

    return root;
}

Node* buildTree(vector<int>& preorder,
                vector<int>& inorder){

    int preIdx=0;

    return helper(preorder,inorder,
                  preIdx,0,inorder.size()-1);
}

void preorderPrint(Node* root){

    if(root==NULL)
        return;

    cout<<root->data<<" ";

    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){

    vector<int> preorder={1,2,4,5,3};

    vector<int> inorder={4,2,5,1,3};

    Node* root=buildTree(preorder,inorder);

    cout<<"Preorder of Constructed Tree: ";

    preorderPrint(root);

    return 0;
}