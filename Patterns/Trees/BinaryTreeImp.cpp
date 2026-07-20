#include<iostream>
#include<bits/stdc++.h>
using namespace std;

   /*
   given preorder-{1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1}
      buld tree
              1 
           /     \
          2        3
          / \     /   \
      NUll  NULL  4      5
                  / \    /  \
              NUll  NULL NULL NULL

               */
class Node{
    public:
    int data;
    Node* left;
    Node* right;   
    
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }    
};

static int idx=-1;
Node* buildTree(vector<int> preorder){
    idx++;

      if(preorder[idx]==-1){
        return NULL;
      }

    Node* root=new Node(preorder[idx]);
    root->left=buildTree(preorder) ; //left
    root->right=buildTree(preorder);  //right

    return root;
}

//preorder traversal
void preOrder(Node* root){
          if(root==NULL){
            return ;
          }
          cout<<root->data<<" ";
          preOrder(root->left);
          preOrder(root->right);
    }


// Inorder traversal
void inOrder(Node* root){
            if(root==NULL){
                return ;
            }
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
    }

// postorder traversal
void postOrder(Node* root){
            if(root==NULL){
                return ;
            }
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
    }

// level order traversal
void levelOrder(Node* root){
        if(root==NULL){
            return ;
        }
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* CurrNode=q.front();
            q.pop();
            if(CurrNode!=NULL){
                cout<<CurrNode->data<<" ";
                if(CurrNode->left!=NULL){
                    q.push(CurrNode->left);
                }
                if(CurrNode->right!=NULL){
                    q.push(CurrNode->right);
                }
            }
            cout<<endl;
        }
    }


int main(){
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
     
   Node* root=buildTree(preorder);
//     cout<<root->data<<endl;
//     cout<<root->left->data<<endl;
//     cout<<root->right->data<<endl;
     

    // preorder traversal
    preOrder(root);

    // inorder traversal
    cout<<endl;
    inOrder(root);

    // postorder traversal
    cout<<endl;
    postOrder(root);

    // level order traversal
    levelOrder(root);

    return 0;
}