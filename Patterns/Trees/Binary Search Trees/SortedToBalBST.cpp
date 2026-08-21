// convert sorted array to balanced binary search tree
#include <bits/stdc++.h>
#include <iostream>

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

void Inorder(Node* root){
        if(root==NULL){
            return;
        }

        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }


    // time complexity: O(n)
    // space complexity: O(n)
    
    Node* SortedArrayToBST(vector<int>& nums,int st,int end){
        if(st>end){
            return NULL;
        }

         int mid=st+(end-st)/2;
         Node* root=new Node(nums[mid]);

         root->left=SortedArrayToBST(nums,st,mid-1);
         root->right=SortedArrayToBST(nums,mid+1,end);

         return root;
    }

    int main(){
        
        vector<int> nums={-10,-3,0,5,9};

        Node* root=SortedArrayToBST(nums,0,nums.size()-1);
    }
 