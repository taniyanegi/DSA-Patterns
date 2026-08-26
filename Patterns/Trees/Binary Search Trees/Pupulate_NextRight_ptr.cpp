// populate the next right pointer for each node in a binary tree

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

Node* buildTree(vector<int>& preorder){
    static int idx=-1;
    idx++;

      if(preorder[idx]==-1){
        return NULL;
      }

    Node* root=new Node(preorder[idx]);
    root->left=buildTree(preorder) ; //left
    root->right=buildTree(preorder);  //right

    return root;
}

// populate the next right pointer for each node in a binary tree
//time complexity=O(n) and space complexity=O(n)
Node* connect(Node* root) {
         if(root==NULL || root->left==NULL){
            return root;
         }
           queue<Node*> q;
           q.push(root);
           q.push(NULL) ; //mark the end of a level
            

            Node* prev=NULL;
            
           while(!q.empty()){
            Node* curr=q.front();
               q.pop();

               if(curr==NULL){
                    if(q.size()==0){
                        break;
                    }
                    else{
                        q.push(NULL);
                    }
               }
                else{
               if(curr->left!=NULL){
                q.push(curr->left);
               }

                if(curr->right!=NULL){
                q.push(curr->right);
               }

               if(prev!=NULL){
                prev->next=curr;
               }
                }
                prev=curr;
           }
           return root;
    }

    int main(){
        vector<int> preorder={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        Node* root=buildTree(preorder);

        Node* ans=connect(root);
        while(ans!=NULL){       
            cout<<ans->data<<" ";
            ans=ans->next;
        }
    }