#include <climits>
#include "tree_node.cpp"

class BinaryTreeMaximumPathSum {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int result = INT_MIN;
        maxPathSum(root, result);
        return result;
    }

private:
public:
    int maxPathSum(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }
        int left_sum = maxPathSum(root->left, result);
        int right_sum = maxPathSum(root->right, result);
        if (max(left_sum, 0) + max(right_sum, 0) + root->val > result) {
            result = max(left_sum, 0) + max(right_sum, 0) + root->val;
        }
        return max(max(left_sum, right_sum), 0) + root->val;
    }
};