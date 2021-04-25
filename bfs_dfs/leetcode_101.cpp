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

// 0ms, 16.5MB, 28:00
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // bfs
        
        using qItem = pair<TreeNode*, int>; // {node, level}
        
        queue<qItem> q;
        q.push({root, 0});
        
        int target_level = 0;
        
        while (!q.empty()) {
            string s = "";
            
            while (!q.empty() && q.front().second == target_level) {
                auto target = q.front(); q.pop();
                
                if (target.first->left == nullptr) s += 'n';
                else {
                    q.push({target.first->left, target_level + 1});
                    s += target.first->left->val;
                }
                if (target.first->right == nullptr) s += 'n';
                else {
                    q.push({target.first->right, target_level + 1});
                    s += target.first->right->val;
                }
            }
            
            for (int i = 0; i < s.length() / 2; i++) {
                if (s[i] != s[s.length() - 1 - i]) return false;
            }
            target_level++;
        }
        return true;
    }
};
