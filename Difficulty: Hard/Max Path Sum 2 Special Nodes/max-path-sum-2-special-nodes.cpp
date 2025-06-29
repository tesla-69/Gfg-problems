/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


class Solution {
public:

    int PathSum(Node* root, int &sum)
    {
        if(!root)
        return 0;
        
        //leaf Node
        if(!root->left && !root->right)
        return root->data;
        
        int Left = PathSum(root->left, sum);
        
        int Right = PathSum(root->right, sum);
        
        //left and right both exist
        if(root->left && root->right)
        {
            sum = max(sum, root->data+Left+Right);
            return root->data+max(Left, Right);
        }
        //only left exist
        if(root->left)
        return root->data+Left;
        //only right exist
        if(root->right)
        return root->data+Right;
        
    }

    int maxPathSum(Node* root)
    {
        // code here
        int sum = INT_MIN;
        int val = PathSum(root, sum);
        
        if(root->left && root->right)
        return sum;
        
        return max(sum, val);
    }
};