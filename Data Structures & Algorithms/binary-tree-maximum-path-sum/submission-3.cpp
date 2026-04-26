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
    pair<int,int> path(TreeNode* root){
        if(!root)
            return {INT_MIN,0};

        auto left = path(root->left);
        auto right = path(root->right);

        int leftDown = max(0, left.second);
        int rightDown = max(0, right.second);

        int include = max(root->val + leftDown + rightDown,root->val);
        return {max({include,left.first,right.first}),max(root->val + rightDown,root->val + leftDown)};
    }
public:
    int maxPathSum(TreeNode* root) {
        return path(root).first;
    }
};
