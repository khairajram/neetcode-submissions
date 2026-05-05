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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st;
        queue<TreeNode*> q;
        if(root)
            q.push(root);

        while(!q.empty()){
            int s = q.size();

            for(int i=1;i<=s;i++){
                auto t = q.front();
                q.pop();
                if(t == NULL){
                    st += "&";
                }else{
                    st += to_string(t->val) + ",";
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }

        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        
        int i = 0;
        int no = 0;
        int n = data.size();

        while(i<n && data[i] != ',')
            no = no * 10 + (data[i++] - '0');
        
        i++;

        TreeNode* root = new TreeNode(no);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();

            for(int j=1;j<=s;j++){
                auto t = q.front();
                q.pop();

                if(i < n && data[i] == '&'){
                    i++;
                }else{
                    no = 0;
                    while(i<n && data[i] != ',')
                        no = no * 10 + (data[i++] - '0');

                    i++;

                    t->left = new TreeNode(no);
                    q.push(t->left);
                }

                if(i < n && data[i] == '&'){
                    i++;
                }else{
                    no = 0;
                    while(i<n && data[i] != ',')
                        no = no * 10 + (data[i++] - '0');
                    
                    i++;

                    t->right = new TreeNode(no);
                    q.push(t->right);
                }
            }
        }


        return root;
    }
};
