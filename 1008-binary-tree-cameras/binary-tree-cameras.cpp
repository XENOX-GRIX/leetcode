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
    map<tuple<TreeNode*, int, int>, int> dp; 
    int findmin(TreeNode* root, int parent, int child){
        if(!root){
            if(child) return 2000; 
            return 0; 
        }
        if(!root->left && !root->right){
            if(child) return 1; 
            if(parent) return 0; 
            return 2000;
        }
        if(dp[{root, parent, child}]) return dp[{root, parent, child}]; 
        if(child){
            return dp[{root, parent, child}] = 1 + min(findmin(root->left,1,0),findmin(root->left,1,1)) + min(findmin(root->right,1,0),findmin(root->right,1,1));
        }
        else if(parent){
            return dp[{root, parent, child}] = min(findmin(root->left,0,0),findmin(root->left,0,1)) + min(findmin(root->right,0,0),findmin(root->right,0,1));
        }
        else{
            int option_left = findmin(root->left,0,1) + min(findmin(root->right,0,0),findmin(root->right,0,1));
            int option_right = findmin(root->right,0,1) + min(findmin(root->left,0,0),findmin(root->left,0,1));
            return dp[{root, parent, child}]= min(option_left, option_right); 
        }

    }
    int minCameraCover(TreeNode* root) {
        return min(findmin(root, 0, 0), findmin(root, 0, 1)); 
    }
};