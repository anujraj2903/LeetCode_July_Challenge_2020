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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int> > ans;
        vector<int> curr;
        stack<TreeNode*> now,next;
        now.push(root);
        int dir=1;
        
        while(!now.empty()){
            auto u=now.top();
            now.pop();
            curr.push_back(u->val);
            
            if(dir){
                if(u->left) next.push(u->left);
                if(u->right) next.push(u->right);
            } else{
                if(u->right) next.push(u->right);
                if(u->left) next.push(u->left);
            }
            
            if(now.empty()){
                dir^=1;
                ans.push_back(curr);
                curr.clear();
                swap(next,now);
            }
        }
        
        return ans;
        
    }
};