/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    
    void inorder(Node* root, vector<int>& arr){
        if(root == NULL) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
  
    bool isSymmetric(Node* root) {
        // Code here
        vector<int> arr;
        inorder(root, arr);
        int i =0;
        int n = arr.size();
        while(i < n){
            if(arr[i]!=arr[n-i-1]) return false;
            i++;
        }
        return true;
    }
};