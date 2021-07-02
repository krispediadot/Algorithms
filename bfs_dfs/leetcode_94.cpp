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
// 0ms, 9.5MB
class Solution {
    vector<int> answer;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int>();
        
        inorderTraversal(root->left);
        answer.push_back(root->val);
        inorderTraversal(root->right);
        
        return answer;
    }
};
