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
    int maximum = INT_MIN;
    int maxGain(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = max(0, maxGain(root->left));
        int right = max(0, maxGain(root->right));
        int U = root->val + left + right;
        maximum = max(maximum, U);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode *root) {
        /*
        Intuition: for single root, left right, try going in U
        but for overall, try taking root + (left/right) + parent + parent ka U
        */
        maxGain(root);
        return maximum;
    }
};
