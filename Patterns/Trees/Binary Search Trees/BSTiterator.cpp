#include <bits/stdc++.h>
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

// time complexity=O(n) and space complexity=O(h) where h is the height of the tree
class BSTIterator {
public:
    stack<Node*> st;

    void storeLeftNodes(Node* root) {

        while(root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(Node* root) {
        storeLeftNodes(root);
    }

    int next() {

        Node* ans = st.top();
        st.pop();

        // Now process the right subtree
        storeLeftNodes(ans->right);

        return ans->data;
    }

    bool hasNext() {
        return !st.empty();
    }
};