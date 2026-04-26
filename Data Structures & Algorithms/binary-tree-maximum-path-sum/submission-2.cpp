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
            return {INT_MIN,INT_MIN};

        auto left = path(root->left);
        auto right = path(root->right);

        int include = max(root->val + left.second + right.second,root->val);
        return {max({include,left.first,right.first}),max(root->val + right.second,root->val + left.second)};
    }
public:
    int maxPathSum(TreeNode* root) {
        return path(root).first;
    }
};
