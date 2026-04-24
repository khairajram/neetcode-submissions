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
    pair<bool,int> depth(TreeNode* root){
        if(!root)
            return {true,0};

        auto left = depth(root->left);
        auto right = depth(root->right);
        
        bool isBal = ((abs(left.second - right.second) <= 1) && left.first && right.first);
        int hei = 1 + max(left.second , right.second);

        return {isBal,hei};
    }
public:
    bool isBalanced(TreeNode* root) {
        return depth(root).first;
    }
};
