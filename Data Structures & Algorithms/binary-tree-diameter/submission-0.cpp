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
    pair<int,int> depth(TreeNode* root){
        if(!root)
            return {0,0};

        auto left = depth(root->left);
        auto right = depth(root->right);

        int len = 1 + max(left.second,right.second);
        int maxi = max({left.second + right.second,left.first,right.first});

        return {maxi,len};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return depth(root).first;
    }
};
