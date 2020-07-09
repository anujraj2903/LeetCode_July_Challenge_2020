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
    map<int,unsigned long> leftmost;
    unsigned long mx=0;
    int widthOfBinaryTree(TreeNode* root) {
        util(root,0,0);
        return mx;
    }
    
    void util(TreeNode* root,int d,unsigned long pos){
        if(!root) return;
        
        if(leftmost.find(d)==leftmost.end()) leftmost[d]=pos;
        mx=max(mx,pos-leftmost[d]+1);
        
        util(root->left,d+1,2*pos);
        util(root->right,d+1,2*pos+1);
    }
};