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

// 4ms, 12.6MB
class Solution {
public:
    TreeNode* findLeftLeap(TreeNode* leftNode) {
        while (leftNode->right != nullptr) {
            leftNode = leftNode->right;
        }
        return leftNode;
    }
    void flatten(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        
        if (root->left != nullptr) flatten(root->left);
        if (root->right != nullptr) flatten(root->right);

        if (root->left != nullptr) {
            findLeftLeap(root->left)->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};
