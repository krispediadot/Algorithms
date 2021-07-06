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

// 12ms, 21.3MB
class Solution {
public:
    bool possible(TreeNode* root, int targetSum, int sum) {
        if (root == nullptr) return false;
        
        sum += root->val;
        
        if (root->left == nullptr && root->right == nullptr && sum == targetSum) return true;
        
        return possible(root->left, targetSum, sum) || possible(root->right, targetSum, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {       
        return root == nullptr ? false : possible(root, targetSum, 0);
    }
};

// 12ms, 21MB
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
         if (root->left == nullptr && root->right == nullptr)
             return (targetSum - root->val == 0) ? true : false;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
