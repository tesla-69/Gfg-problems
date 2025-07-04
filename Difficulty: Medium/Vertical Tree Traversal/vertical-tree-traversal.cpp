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
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        map<int,map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            nodes[x][y].push_back(node->data);
            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        }
        vector<vector<int>> ans;
        for(auto it : nodes) {
            vector<int> t;
            for(auto p : it.second) {
                for(q : p.second) {
                    t.push_back(q);
                }
            }
            ans.push_back(t);
        }
        return ans;
        
    }
};










