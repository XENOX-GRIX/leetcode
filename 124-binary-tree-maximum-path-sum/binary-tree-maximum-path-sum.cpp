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
    int ans = INT_MIN; 
    int dfs(TreeNode* root) {
        if(!root->left && !root->right) {
            ans = max(ans, root->val); 
            return root->val;
        }
        int left = 0; 
        int right = 0; 
        if(root->left) left = dfs(root->left);
        if(root->right) right = dfs(root->right); 
        ans = max({ans, left + right + root->val, root->val, left + root->val, right + root->val}); 
        return max({left + root->val, right + root->val, root->val});
    }
    int maxPathSum(TreeNode* root) {
        ans = max(ans,dfs(root));
        return ans;
    }
};