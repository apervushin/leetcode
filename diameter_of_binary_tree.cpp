#include "tree_node.cpp"

class DiameterOfBinaryTree {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        diameterOfBinaryTree(root, result);
        return max(result - 1, 0);
    }

private:
    int diameterOfBinaryTree(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }
        int left = diameterOfBinaryTree(root->left, result);
        int right = diameterOfBinaryTree(root->right, result);
        if (result < left + right + 1) {
            result = left + right + 1;
        }
        return max(left, right) + 1;
    }
};