/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void addright(Node* root, vector<int>& right) {
        if(!root || (root->left == NULL && root->right==NULL)) return;
        
        right.push_back(root->data);
        if(root->right) addright(root->right, right);
        else addright(root->left, right);
    } 
    void addleaf(Node* root, vector<int>& leaf) {
        if(!root) return;
        if(root->left == NULL && root->right==NULL) {
            leaf.push_back(root->data);
            return;
        }
        addleaf(root->left, leaf);
        addleaf(root->right, leaf);
    }
    
    void addleft(Node* root, vector<int>& left) {
        if(!root || (root->left == NULL && root->right==NULL)) return;
        
        left.push_back(root->data);
        if(root->left) addleft(root->left, left);
        else addleft(root->right, left);
    } 
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root) return {};
        if(!root->left && !root->right) return {root->data};
        vector<int> left;
        vector<int> right;
        vector<int>leaf;
        vector<int> ans;
        
        addleft(root->left, left);
        addleaf(root, leaf);
        addright(root->right, right);
        
        ans.push_back(root->data);
        
        for(auto it : left) ans.push_back(it);
        for(auto it: leaf) ans.push_back(it);
        reverse(right.begin(), right.end());
        for(auto it: right) ans.push_back(it);
        
        return ans;
        
    }
};