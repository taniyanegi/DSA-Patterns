// iterative approach of tree traversals
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


// preorder traversal
vector<int> preorder(Node* root) {

    vector<int> ans;

    if(root == NULL)
        return ans;

    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {

        Node* curr = st.top();
        st.pop();

        ans.push_back(curr->data);

        if(curr->right)
            st.push(curr->right);

        if(curr->left)
            st.push(curr->left);
    }
    return ans;
}

 
// inorder traversal

vector<int> inorder(Node* root) {

    vector<int> ans;

    stack<Node*> st;

    Node* curr = root;

    while(curr != NULL || !st.empty()) {

        // Go left
        while(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        // Process node
        curr = st.top();
        st.pop();

        ans.push_back(curr->data);

        // Go right
        curr = curr->right;
    }

    return ans;
}


// postorder traversal

vector<int> postorder(Node* root) {

    vector<int> ans;

    if(root == NULL)
        return ans;

    stack<Node*> st1;
    stack<Node*> st2;

    st1.push(root);

    while(!st1.empty()) {

        Node* curr = st1.top();
        st1.pop();

        st2.push(curr);

        if(curr->left)
            st1.push(curr->left);

        if(curr->right)
            st1.push(curr->right);
    }

    while(!st2.empty()) {

        ans.push_back(st2.top()->data);
        st2.pop();
    }

    return ans;
}


int main() {

    // example usage
    vector<int> preorder1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder1);

    vector<int> pre = preorder(root);
    cout << "Preorder Traversal: ";
    for(int val : pre)
        cout << val << " ";
    cout << endl;

    vector<int> in = inorder(root);
    cout << "Inorder Traversal: ";
    for(int val : in)
        cout << val << " ";
    cout << endl;

    vector<int> post = postorder(root);
    cout << "Postorder Traversal: ";
    for(int val : post)
        cout << val << " ";
    cout << endl;

    return 0;
}
