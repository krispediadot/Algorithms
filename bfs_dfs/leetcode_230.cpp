// 12ms, 14.3MB, 00:31:00
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
    int kthSmallest(TreeNode* root, int k) {
        // inordered 값 가져오기 
        
        int cnt = 0;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            auto target = st.top();
            
            if (target->left == nullptr && target->right == nullptr) {
                cnt++;
                st.pop();
                if (cnt == k) return target->val;
                continue;
            }
            
            if (target->right != nullptr) {
                st.pop();
                st.push(target->right);
                st.push(target);
                
                target->right = nullptr;
            }
            
            if (target->left != nullptr) {
                st.push(target->left);
                target->left = nullptr;
            }
        }
        return -1; 
    }
};
