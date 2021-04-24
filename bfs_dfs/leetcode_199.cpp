// 4ms, 12MB, 00:10:00
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        
        if (root == nullptr) return answer;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int prev = -200;
        int prev_level = -1;
        
        while (!q.empty()) {
            auto target = q.front(); q.pop();
            auto node = target.first;
            int level = target.second;
            
            if (level > 0 && level != prev_level) 
                answer.push_back(prev);
            
            if (node->left != nullptr) q.push({node->left, level + 1});
            if (node->right != nullptr) q.push({node->right, level + 1});
            
            prev = node->val;
            prev_level = level;
        }
        
        answer.push_back(prev);
        
        return answer;
    }
};
