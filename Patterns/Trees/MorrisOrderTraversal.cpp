// Morris order traversal of a binary tree without using recursion or stack
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

// time complexity: O(n)
// space complexity: O(1)

 vector<int> MorrisinorderTraversal(Node* root) {
          vector<int> ans;

          Node* curr=root;

          while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                // find thr IP
                Node* IP=curr->left;

                while(IP->right!=NULL && IP->right!=curr){
                    IP=IP->right;
                }

                if(IP->right==NULL){
                    IP->right=curr;    // create
                    curr=curr->left;
                }
                else{
                    IP->right=NULL;     // destroy
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
          }
       return ans;
    }

    int main() {
        vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
        Node* root = buildTree(preorder);

        vector<int> inorderTraversal = MorrisinorderTraversal(root);

        cout << "Morris Inorder Traversal: ";
        for (int val : inorderTraversal) {
            cout << val << " ";
        }
        cout << endl;

        return 0;
    }
