//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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

Node* newNode(int val) {
    return new Node(val);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
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

Node* newNode(int val) {
    return new Node(val);
}
*/

/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
  
    int height(Node*root){
        if(root == NULL) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return max(lh,rh) +1 ;
    }
    
    pair<int,int> diameterFast(Node*root){
        if(root==NULL) return {0,0};
        
        pair<int,int> leftd = diameterFast(root->left);
        pair<int,int> rightd = diameterFast(root->right);
        
        int op1 = leftd.first;
        int op2 = rightd.first;
        int op3 = (leftd.second + rightd.second)+1;
        
        pair<int,int> ans;
        ans.first = max({op1,op2,op3});
        ans.second = max(leftd.second , rightd.second)+1;
        
        return ans;
    }
    
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        // if(root==NULL) return 0;
        
        // int opt1= diameter(root->left);
        // int opt2=diameter(root->right);
        // int opt3=height(root->left) + height(root->right) +1;
        
        // int ans = max({opt1,opt2,opt3});
        // return ans;
        return diameterFast(root).first - 1;
        
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends