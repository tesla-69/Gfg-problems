//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
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
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// class Solution {
//   public:
  
//     void preorder(Node* root, vector<int>&pre){
//         if(root == NULL) return;
//         pre.push_back(root->data);
//         preorder(root->left,pre);
//         preorder(root->right,pre);
//     }
    
//     // Function to serialize a tree and return a list containing nodes of tree.
//     vector<int> serialize(Node *root) {
//         // Your code here
//         vector<int> pre;
//         preorder(root,pre);
//         return pre;
//     }
    
//     void inorder(Node*root, vector<int>&in){
//         if(root == NULL) return;
//         inorder(root->left,in);
//         in.push_back(root->data);
//         inorder(root->right,in);
//     }
    
//     void formtree(Node*&root,int l ,int r, vector<int>&arr,int n){
//         if(l>=n && r>=n) return ;
//         else if(r<n && l>=n) {
//             Node* newnode = new Node(arr[r]);
//             root->right = newnode;
//         }
//         else if(l<n && r>=n) {
//             Node*newnode = new Node(arr[l]);
//             root->left = newnode;
//         }
//         else {
//             Node* newnode = new Node(arr[r]);
//             root->right = newnode;
//             Node*newnoder = new Node(arr[l]);
//             root->left = newnoder;
//         }
//         formtree(root->left, 2*l+1, 2*l+2, arr,n);
//         formtree(root->right, 2*r+1, 2*r+2, arr,n);
//     }
    
//     // Function to deserialize a list and construct the tree.
//     Node *deSerialize(vector<int> &arr) {
//         // Your code here
//         Node* root = new Node(arr[0]);
//         int i = 0;
//         int n = arr.size();
        
//         formtree(root,1,2,arr,n);
        
//         vector<int>in;
//         inorder(root,in);
//         for(int i=0;i<n;i++) cout<<in[i]<<" ";
//         cout<<endl;
        
//         return root;
//     }
// };
class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    void in(Node*root,vector<int>&arr)
    {
        if(root==NULL)
        {
            return;
        }
        
        in(root->left,arr);
        arr.push_back(root->data);
        in(root->right,arr);
    }
    Node* bsthelper(vector<int>&arr,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        
        int mid=(start+end)/2;
        Node*root=new Node(arr[mid]);
        root->left=bsthelper(arr,start,mid-1);
        
        root->right=bsthelper(arr,mid+1,end);
        
        return root;
    }
    vector<int> serialize(Node *root) 
    {
        // Your code here
        vector<int>arr;
        in(root,arr);
        return arr;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        return bsthelper(arr,0,arr.size()-1);
        
    }
};



//{ Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node) {
    if (node == NULL)
        return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    // cout << "Deleting node: " << node->data << endl;
    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node **node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node *temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);

        cout << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends