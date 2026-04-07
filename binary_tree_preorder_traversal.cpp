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
    vector<int> answer = {};
    vector<int> preorderTraversal(TreeNode *root) {
        // Root left right
        if (root == NULL) {
            return {};
        }
        // Print the root first
        answer.push_back(root->val);

        // left
        preorderTraversal(root->left);

        // right
        preorderTraversal(root->right);
        return answer;
    }
};
