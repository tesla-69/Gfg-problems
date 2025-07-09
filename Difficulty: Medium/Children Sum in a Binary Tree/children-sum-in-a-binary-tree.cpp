/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int isSumProperty(Node *root) {
        if (!root || (!root->left && !root->right)) return 1;  // leaf or null node

        int childSum = 0;
        if (root->left) childSum += root->left->data;
        if (root->right) childSum += root->right->data;

        if (root->data == childSum) {
            return isSumProperty(root->left) && isSumProperty(root->right);
        }

        return 0;
    }
};







