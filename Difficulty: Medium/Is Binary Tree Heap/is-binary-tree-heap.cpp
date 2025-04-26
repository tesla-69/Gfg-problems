//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
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

// Function to Build Tree
Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    int cntnodes(struct Node*root) {
        if(root == NULL) return 0;
        
        return 1+cntnodes(root->left) + cntnodes(root->right);
    }
    
    bool isCBT(struct Node*root , int cnt , int i) {
        if(root == NULL) return true;
        if(i>=cnt) return false;
        if(isCBT(root->left,cnt,2*i+1) && isCBT(root->right,cnt,2*i+2)) return true;
        else return false;
    }
    
    bool property(struct Node*root) {
        if(root->left == NULL && root->right == NULL) return true;  
        
        if(root -> right == NULL) {
            return (root->data > root->left->data);
        }
        
        else{
            if(property(root->right) && property(root->left) && 
            (root->data > root->right->data) && (root->data > root->left->data)) 
                return true;
            else return false;
        }
    }
  
    bool isHeap(struct Node* tree) {
        // code here
        int count = cntnodes(tree);
        
        if(isCBT(tree,count , 0) && property(tree)){
            return true;
        }
        else return false;
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends