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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        queue<TreeNode*> q;

        if(root)
            q.push(root);

        while(!q.empty()){
            int size = q.size();

            int num = INT_MIN;

            for(int i=0;i<size;i++){
                auto front = q.front();
                q.pop();

                num = front->val;

                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }

            ans.push_back(num);
        }

        return ans;
    }
};
