#include "tree_node.cpp"

class SymmetricTree {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root;
        TreeNode* right = root;
        return isSymmetric(left, right);
    }

private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr) || left->val != right->val) {
            return false;
        }
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};