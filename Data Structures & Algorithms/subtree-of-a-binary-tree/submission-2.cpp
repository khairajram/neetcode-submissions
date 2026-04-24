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
    bool same(TreeNode* p, TreeNode* q){
        if(!p && !q)
            return true;
        else if((!p && q) || (p && !q))
            return false;
        else if(p->val != q->val)
            return false;

        return same(p->left,q->left) && same(p->right,q->right);
    }

    bool sub(TreeNode* root, TreeNode* subRoot){
        if(!root)
            return false;   
        if(root->val == subRoot->val && same(root,subRoot))
            return true;
        
        return sub(root->left,subRoot) || sub(root->right,subRoot);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return sub(root,subRoot);
    }
};
