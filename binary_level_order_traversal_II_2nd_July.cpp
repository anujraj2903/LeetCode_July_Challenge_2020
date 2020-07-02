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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);q.push(NULL);
        vector<int> cur;
        while(!q.empty()){
            TreeNode* u=q.front();
            q.pop();
            
            if(u==NULL){
                res.push_back(cur);
                cur.clear();
                if(!q.empty()) q.push(NULL);
                continue;
            }
            
            cur.push_back(u->val);
            
            if(u->left) q.push(u->left);
            if(u->right) q.push(u->right);
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};