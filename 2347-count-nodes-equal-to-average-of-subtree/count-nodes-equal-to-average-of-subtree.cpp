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
    int ans; 
    pair<int, int> findAverage(TreeNode* root){
        if(!root->left && !root->right){
            ans++; 
            return {1, root->val}; 
        }
        pair<int, int> l, r, x; 
        x = {1, root->val}; 
        if(root->left) {
            l = findAverage(root->left); 
            x.first+=l.first; 
            x.second+=l.second; 
        }
        if(root->right) {
            r = findAverage(root->right); 
            x.first+=r.first; 
            x.second+=r.second; 
        }
        if(x.second/x.first == root->val) ans++; 
        return x; 
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0; 
        findAverage(root); 
        return ans;
    }
};