/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> answer = {};
        queue<TreeNode *> q = {};
        q.push(root);
        bool rotated = false;
        while (!q.empty()) {
            int n = q.size();
            vector<int> to_push = {};
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (rotated) {
                    to_push.insert(to_push.begin() + 0, node->val);
                } else
                    to_push.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            if (rotated) {
                rotated = false;
            } else {
                rotated = true;
            }
            answer.push_back(to_push);
        }
        return answer;
    }
};
