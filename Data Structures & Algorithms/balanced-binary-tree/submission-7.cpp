/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int left = heightcheck(root->left);
        int right = heightcheck(root->right);
        if (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    }
    int greater(int a, int b){
        if(a >= b){
            return a;
        }
        return b;
    }

    int heightcheck(TreeNode* node){
        if(node == nullptr){
            return 0; // null node has no height
        }
        int a = heightcheck(node->left);
        int b = heightcheck(node->right);
        return 1 + greater(a,b);
    }
};
