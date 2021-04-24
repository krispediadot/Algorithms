// 4ms, 19.1MB, 00:05:00

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
    int maxDepth(TreeNode* root) {
        int answer = 0;
        
        if (root == nullptr) return answer;
        
        queue<pair<TreeNode*, int>> q; //{node, level}
        q.push({root, 1});
        
        while (!q.empty()) {
            auto target = q.front(); q.pop();
            
            answer = max(answer, target.second);
            
            if (target.first->left != nullptr) q.push({target.first->left, target.second + 1});
            if (target.first->right != nullptr) q.push({target.first->right, target.second + 1});
        }
        
        return answer;
    }
};
