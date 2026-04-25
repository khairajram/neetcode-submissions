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
    void good(TreeNode* root,int maxi,int &ans){
        if(!root)
            return;

        maxi = max(maxi,root->val);

        if(root->val == maxi)
            ans++;
        
        good(root->left,maxi,ans);
        good(root->right,maxi,ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        good(root,INT_MIN,ans);

        return ans;
    }
};
