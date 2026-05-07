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
    int i = 0;
    TreeNode* build(TreeNode* root,vector<int>& preorder,unordered_map<int,int> &mp,int inL,int inR){
        if(inL > inR)
            return nullptr;

        root = new TreeNode(preorder[i]);
        int idx = mp[preorder[i++]];

        

        root->left = build(root->left,preorder,mp,inL,idx-1);
        root->right = build(root->right,preorder,mp,idx+1,inR);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;

        TreeNode* root;
        root = build(root,preorder,mp,0,inorder.size()-1);
        return root;
    }
};
