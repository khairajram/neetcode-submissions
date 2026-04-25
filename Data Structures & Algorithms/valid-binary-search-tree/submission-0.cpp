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
    bool ValidBST(TreeNode* root){
        if(!root)
            return true;

        if(root->left && root->val < root->left->val)
            return false;

        if(root->right && root->val > root->right->val)
            return false;

        bool left = ValidBST(root->left);
        bool right = ValidBST(root->right);


        return (left && right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return ValidBST(root);
    }
};
