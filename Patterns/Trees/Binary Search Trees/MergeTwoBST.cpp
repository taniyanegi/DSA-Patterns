// merge two BSt's
#include<iostream>
#include<vector>

using namespace std;

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

Node *insert(Node *root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node *buildBST(vector<int> &arr) {
    Node *root=NULL;
    
    for(int val:arr){
        root=insert(root,val);
    }

    return root;
}

void inorder(Node *root, vector<int> &arr) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node *buildBSTFromSorted(vector<int> &arr, int st, int end) {
    if (st > end) {
        return NULL;
    }

    int mid = (st + end) / 2;

    Node *root = new Node(arr[mid]);

    root->left = buildBSTFromSorted(arr, st, mid - 1);
    root->right = buildBSTFromSorted(arr, mid + 1, end);

    return root;
}

Node *mergeBST(Node *root1, Node *root2) {
     vector<int> arr1,arr2;
     inorder(root1,arr1);
     inorder(root2,arr2);

     int i=0;
     int j=0;

     vector<int> temp; // final bst sorted sequence

        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            }
            else{
                temp.push_back(arr2[j]);
                j++;
            }
        }
          while(i<arr1.size()){
                temp.push_back(arr1[i]);
                i++;
            }

            while(j<arr2.size()){
                temp.push_back(arr2[j]);
                j++;
            }

         return   buildBSTFromSorted(temp,0,temp.size()-1);   // sorted array,st,end
}