// top view of binary tree

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

void topView(Node* root) {
        // code here
         queue<pair<Node*, int>> q;
         map<int,int> mp;
         q.push({root,0});

          while(!q.empty()){
            Node* curr=q.front().first;
            int   currHD=q.front().second;
            q.pop();

            if(curr->left!=NULL){
                q.push({curr->left, currHD-1});
            }
            if(curr->right!=NULL){
                q.push({curr->right, currHD+1});
            }
            if(mp.find(currHD)==mp.end()){
                mp[currHD]=curr->data;
            }
         }

         for(auto it:mp){
            cout<<it.second<<" ";
         }
    }

int main(){
    // example usage
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
     
    Node* root=buildTree(preorder);
    topView(root);
    return 0;
}