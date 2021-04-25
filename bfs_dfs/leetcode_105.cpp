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
// 136ms, 161.5MB, 00:54:43
class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        if (preorder.size() == 1) return new TreeNode(preorder[0]);
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        vector<int> left_preorder;
        vector<int> left_inorder;
        vector<int> right_preorder;
        vector<int> right_inorder;
        
        bool found_root = false;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root->val) {
                found_root = true;
                continue;
            }
            
            if (found_root) right_inorder.push_back(inorder[i]);
            else left_inorder.push_back(inorder[i]);
        }
        
        for (int i = 1; i < preorder.size(); i++) {
            if (left_preorder.size() < left_inorder.size()) 
                left_preorder.push_back(preorder[i]);
            else right_preorder.push_back(preorder[i]);
        }
        
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        
        return root;
    }
};
