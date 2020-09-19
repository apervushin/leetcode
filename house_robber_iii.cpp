#include "tree_node.cpp"

class HouseRobberIII {
public:
    int rob(TreeNode* root) {
        auto result = rob(root, true);
        return max(result.first, result.second);
    }

private:
    pair<int, int> rob(TreeNode* root, bool flag) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto result = rob(root->left, !flag);
        auto right_result = rob(root->right, !flag);
        result.first += right_result.first;
        result.second += right_result.second;

        if (flag) {
            if (result.first + root->val > result.second) {
                result.first += root->val;
            } else {
                result.first = result.second;
            }
        } else {
            if (result.second + root->val > result.first) {
                result.second += root->val;
            } else {
                result.second = result.first;
            }
        }
        return result;
    }
};
