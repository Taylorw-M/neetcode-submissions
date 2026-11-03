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
        if (root == nullptr) { //added nullptr check
            return true;
        }
        int left = heightcheck(root->left);
        int right = heightcheck(root->right);
        if (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {//was changed
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
            return 0;
        }
        int a = heightcheck(node->left);
        int b = heightcheck(node->right);
        return 1 + greater(a,b);//changed to 1+ not sure why
    }
};
