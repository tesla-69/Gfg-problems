/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    Node* find(Node* root, int tar) {
        if(root == NULL) return NULL;
        if(root->data == tar) return root;
        
        Node* left = find(root->left, tar);
        if(left) return left;
        Node* right = find(root->right, tar);
        if(right) return right;
        return NULL;
    }
  
    int h(Node* root) {
        if(root == NULL) return 0;
        int left = h(root->left);
        int right = h(root->right);
        
        return 1 + max(left , right);
    }
  
    int solve(Node* root, int &timer, int target) {
        if(root == NULL) return 0;
        if(root->data == target) return -1;
        
        int left = solve(root->left, timer, target);
        int right = solve(root->right, timer,  target);
        
        if(left < 0) {
            timer = max(timer, abs(left) + right);
            return left - 1;
        }
        if(right < 0) {
            timer = max(timer, (left) + abs(right));
            return right - 1;
        }
        return 1 + max(left , right);
    }
  
    int minTime(Node* root, int target) {
        // code here
        int timer = 0;
        solve(root, timer, target);
        Node* burn = find(root, target);
        int height = h(burn)-1;
        return max(height, timer);
        
    }
};