// max width of binary tree

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


int widthOfBinaryTree(Node* root) {
          // store node and its indes- we are using CBT(complete binary tree) based indexing here
              queue<pair<Node*,unsigned long long int>> q;
               q.push({root,0});

               int maxWidth=0;

               while(!q.empty()){
                   int currLevelSize=q.size();
                   unsigned long long int startIdx=q.front().second;
                   unsigned long long int endIdx=q.back().second;

                   maxWidth=max(maxWidth,int(endIdx-startIdx)+1);

                for(int i=0;i<currLevelSize;i++){
                   auto currNode=q.front();
                     q.pop();

                   if(currNode.first->left){
                     q.push({currNode.first->left,2*(currNode.second)+1});
                   }

                    if(currNode.first ->right){
                     q.push({currNode.first->right,2*currNode.second+2});
                   }
               }

               }
               return maxWidth;
    }

    int main(){
        
        // example usage
        vector<int> preorder={1,2,-1,-1,3,4,-1,-1,3,-1,-1,5,-1,-1};
         
        Node* root=buildTree(preorder);
        cout << "Maximum width of the binary tree is: " << widthOfBinaryTree(root) << endl;
        return 0;
    }