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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return same(p,q);
    }
};
